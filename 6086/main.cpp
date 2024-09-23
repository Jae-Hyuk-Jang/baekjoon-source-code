#include<bits/stdc++.h>
#define MX 52
#define INF 1e9
using namespace std;


int c[MX][MX];
int f[MX][MX];
int d[MX];

int result;

vector<int> adj[MX];

int getId(char c) {
	int ret = 0;
	if (c >= 97) {
		ret = c - 97;
		ret += 26;
	}
	else ret = c - 65;
	return ret;
}


void maxFlow(int start, int end) {
	while (1) {
		fill(d, d + MX, -1);
		queue<int> q;
		q.push(start);
		while (!q.empty()) {
			int x = q.front();
			q.pop();

			for (int i = 0; i < adj[x].size(); i++) {
				int y = adj[x][i];
				// �湮���� ���� ��� �߿��� �뷮�� ���� ���
				if (c[x][y] - f[x][y] > 0 && d[y] == -1) {
					q.push(y);
					d[y] = x; //  ��θ� ����մϴ�.
					if (y == end) break; // �������� ������ ��� ���� 

				}
			}
		}
		//  ��� ��θ� �� ã�� �ڿ� Ż���մϴ�.
		if (d[end] == -1) break;
		int flow = INF;
		for (int i = end; i != start; i = d[i]) {
			flow = min(flow, c[d[i]][i] - f[d[i]][i]);
		}

		// �ּ� ������ŭ �߰��մϴ�. 
		for (int i = end; i != start; i = d[i]) {
			f[d[i]][i] += flow;
			f[i][d[i]] -= flow;
		}
		result += flow;
	}
}


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int N; cin >> N;
	for (int i = 0; i < N; i++) {
		char a, b; int w; cin >> a >> b >> w;
		int A = getId(a);
		int B = getId(b);

		adj[A].push_back(B);
		adj[B].push_back(A);
		c[A][B] += w;
		c[B][A] += w;
	}

	maxFlow(0, 25);
	cout << result << '\n';
	return 0;
}
