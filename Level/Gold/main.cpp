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
	p[v] = u;
	return;
}

bool issame(int u, int v) {
	return find(u) == find(v);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int N, K; cin >> N >> K;
	init(N);
	vector<pair<int, int>> v;
	while (K--) {
		int a, b; cin >> a >> b;
		v.push_back({ a, b });
		/*if (issame(a, b)) continue;
		for (int i = a + 1; i <= b; i++) unite(a, i);*/
	}

	sort(v.begin(), v.end());

	int last = 0;
	for (int i = 0; i < v.size(); i++) {
		int s = v[i].first;
		int e = v[i].second;
		s = max(s, last);
		for (int i = s; i <= e; i++) unite(s, i);
		last = max(last, e);
	} 

	int ans = 0;
	for (int i = 1; i <= N; i++) {
		if (p[i] == -1) ans++;
	}
	cout << ans << endl;
	//for (int i = 1; i <= N; i++) {
	//	cout << p[i] << ' ';
	//}
	//cout << endl;
	return 0;
}