#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
#include <queue>
#include <algorithm>

using namespace std;

class TreeNode {
public:
    unordered_map<int, int> edges; // 인접 노드와 간선 가중치
    int value;

    TreeNode() : value(1) {}
};

class Forest {
private:
    vector<TreeNode> nodes;
    vector<int> parent;

public:
    Forest(int n) : nodes(n + 1), parent(n + 1) {
        for (int i = 1; i <= n; i++) {
            parent[i] = i;
        }
    }

    int find(int a) {
        if (parent[a] != a) {
            parent[a] = find(parent[a]);
        }
        return parent[a];
    }

    void unionNodes(int a, int b) {
        int rootA = find(a);
        int rootB = find(b);
        if (rootA != rootB) {
            parent[rootB] = rootA;
        }
    }

    void addEdge(int a, int b, int weight) {
        nodes[a].edges[b] = weight;
        nodes[b].edges[a] = weight;
        unionNodes(a, b);
    }

    void removeEdge(int a, int b) {
        nodes[a].edges.erase(b);
        nodes[b].edges.erase(a);
    }

    int toggleValue(int a) {
        nodes[a].value = 1 - nodes[a].value;
        return calculateMinWeightedDistance(a);
    }

    int calculateMinWeightedDistance(int a) {
        // 같은 컴포넌트의 모든 노드 찾기
        set<int> component;
        queue<int> q;
        vector<bool> visited(nodes.size(), false);

        q.push(a);
        visited[a] = true;

        while (!q.empty()) {
            int current = q.front();
            q.pop();
            component.insert(current);
            for (const auto& edge : nodes[current].edges) {
                if (!visited[edge.first]) {
                    visited[edge.first] = true;
                    q.push(edge.first);
                }
            }
        }

        // 가중치 거리 계산
        int minDistance = INT_MAX;
        for (int v : component) {
            int totalDistance = 0;
            for (int u : component) {
                totalDistance += getDistance(v, u) * nodes[u].value;
            }
            minDistance = min(minDistance, totalDistance);
        }

        return minDistance;
    }

    int getDistance(int a, int b) {
        if (a == b) return 0;

        queue<pair<int, int>> q; // (노드, 거리)
        set<int> visited;

        q.push({ a, 0 });
        visited.insert(a);

        while (!q.empty()) {
            int current = q.front().first;
            int dist = q.front().second;
            q.pop();

            for (const auto& edge : nodes[current].edges) {
                if (edge.first == b) {
                    return dist + edge.second;
                }
                if (!visited.count(edge.first)) {
                    visited.insert(edge.first);
                    q.push({ edge.first, dist + edge.second });
                }
            }
        }
        return INT_MAX; // 연결되지 않은 경우
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, Q;
    cin >> N >> Q;

    Forest forest(N);
    int lastS = 0; // 이전 쿼리의 결과 저장

    while (Q--) {
        int type;
        cin >> type;

        if (type == 1) {
            int x, a, b, c;
            cin >> x >> a >> b >> c;
            // 정점 번호 복호화
            int decodedA = (a - 1 + lastS) % N + 1;
            int decodedB = (b - 1 + lastS) % N + 1;
            forest.addEdge(decodedA, decodedB, c);
        }
        else if (type == 2) {
            int x, a, b;
            cin >> x >> a >> b;
            // 정점 번호 복호화
            int decodedA = (a - 1 + lastS) % N + 1;
            int decodedB = (b - 1 + lastS) % N + 1;
            forest.removeEdge(decodedA, decodedB);
        }
        else if (type == 3) {
            int x, a;
            cin >> x >> a;
            // 정점 번호 복호화
            int decodedA = (a - 1 + lastS) % N + 1;
            lastS = forest.toggleValue(decodedA);
            cout << lastS << "\n";
        }
    }

    return 0;
}