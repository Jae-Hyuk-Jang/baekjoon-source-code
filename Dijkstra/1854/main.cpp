#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

vector<pii> adj[1010];
priority_queue<int> heap[1010];
priority_queue<pii, vector<pii>, greater<pii>> pq;
int n, m, k;
int a, b, c;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m >> k;
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;
		adj[a].push_back({ b, c });
	}

	pq.push({ 0, 1 });
	heap[1].push(0);

	while (!pq.empty()) {
		int now = pq.top().second;
		int acc = pq.top().first;
		pq.pop();

		for (const auto& i : adj[now]) {
			int next = i.first;
			int cost = i.second + acc;

			if (int(heap[next].size()) < k) {
				heap[next].push(cost);
				pq.push({ cost, next });
			}
			else if (int(heap[next].top()) > cost) {
				heap[next].pop();
				heap[next].push(cost);
				pq.push({ cost, next });
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		if (int(heap[i].size()) != k) cout << -1 << '\n';
		else cout << heap[i].top() << '\n';
	}
	return 0;
}


//#include <iostream>
//#include <algorithm>
//#include <vector>
//#include <queue>
//#include <tuple>
//
//using namespace std;
///*
//1. k��° �ִܰ�� ���ϱ�
//2. ElogV�� ���� ����ϱ�
//3. node�� �ִ� �� �迭�� ������ֱ�
//4. node[cur]�� ����� k �̻��� ��� �����ϰ� �����ϱ�
//5. �� ����� ����� üũ�ϰ� ����� k�� �迭�� top�� ������ֱ�
//*/
//const int INF = 0x7fffffff;
//
//
//
//struct Edge
//{
//	int to, cost;
//
//};
//struct cmp
//{
//	bool operator()(const Edge& a, const Edge& b) {
//		return a.cost > b.cost;
//	}
//};
//
//priority_queue<int> node[1005];
//vector<Edge> adj[1005];
//priority_queue<Edge, vector<Edge>, cmp> pq;
//int n, m, k;
//
//int main() {
//	//���� ������� ���ؼ� ����ϱ�
//	ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
//	cin >> n >> m >> k;
//	while (m--)
//	{
//		int from, to, cost;
//		cin >> from >> to >> cost;
//		adj[from].push_back({ to, cost });
//	}
//	node[1].push(0);
//	pq.push({ 1, 0 });
//
//	while (!pq.empty())
//	{
//		auto cur = pq.top(); pq.pop();
//		if (node[cur.to].top() < cur.cost) continue;
//
//		for (auto nxt : adj[cur.to])
//		{
//			if (node[nxt.to].size() < k) {
//				node[nxt.to].push({ cur.cost + nxt.cost });
//				pq.push({ nxt.to, cur.cost + nxt.cost });
//			}
//			else if (node[nxt.to].top() > cur.cost + nxt.cost) {
//				node[nxt.to].pop();
//				node[nxt.to].push({ cur.cost + nxt.cost });
//				pq.push({ nxt.to, cur.cost + nxt.cost });
//			}
//		}
//	}
//	for (int i = 1; i <= n; i++)
//	{
//		if (node[i].size() == k) {
//			cout << node[i].top() << '\n';
//		}
//		else
//		{
//			cout << -1 << '\n';
//		}
//	}
//
//
//	return 0;
//}
