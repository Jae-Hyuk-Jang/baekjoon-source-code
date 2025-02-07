#include<bits/stdc++.h>
#define MX 1000001
using namespace std;

int p[MX];

void init(int N) {
	for (int i = 0; i <= N; i++) p[i] = -1;
}

int find(int x) {
	if (p[x] < 0) return x;
	return p[x] = find(p[x]);
}

void unite(int u, int v) {
	u = find(u);
	v = find(v);
	if (u == v) return;
	if (p[v] < p[u]) swap(u, v);
	if (p[u] == p[v]) p[u]--;
	p[v] = u;
	return;
}

bool issame(int u, int v) {
	return find(u) == find(v);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int T; cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		cout << "Scenario " << tc << ":\n";
		int N, K; cin >> N >> K;
		init(N);
		while (K--) {
			int a, b; cin >> a >> b;
			unite(a, b);
		}
		int M; cin >> M;
		while (M--) {
			int u, v; cin >> u >> v;
			cout << issame(u, v) << '\n';
		}
		cout << '\n';
	}
	
	return 0;
}