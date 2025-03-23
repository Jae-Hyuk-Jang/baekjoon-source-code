#include<bits/stdc++.h>
#define MX 600
using namespace std;
using ll = long long;
using pii = pair<int, int>;


vector<int> g[MX];
int arr[MX][3];
vector<int> par(MX, -1);
bool chk[MX];


int f(string s) {
	int ret = 0;
	int acc = 1;

	for (int i = s.size()- 1; i >= 1; i--) {
		ret += (s[i] - '0') * acc;
		acc *= 10;
	}
	return ret;
}

int match(int v) {
	for (auto i : g[v]) {
		if (chk[i]) continue;
		chk[i] = true;
		if (par[i] == -1 || match(par[i])) {
			par[i] = v;
			return 1;
		}
	}
	return 0;
}


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int T; cin >> T;
	while (T--) {
		int n, m, k; cin >> n >> m >> k;

		for (int i = 0; i < k; i++) {
			string a, b; cin >> a >> b;
			if (a[0] == 'C') {
				arr[i][2] = 1;
				arr[i][0] = f(a);
				arr[i][1] = f(b);
			}
			else {
				arr[i][2] = 0;
				arr[i][0] = f(b);
				arr[i][1] = f(a);
			}
		}

		for (int i = 0; i < k; i++) {
			for (int j = i + 1; j < k; j++) {
				if (arr[i][2] == arr[j][2]) continue;
				if ((arr[i][0] == arr[j][0] || arr[i][1] == arr[j][1]) && arr[i][2] != arr[j][2]) {
					if (arr[i][2]) g[i].push_back(j);
					else g[j].push_back(i);
				}
			}
		}

		int ans = 0;
		for (int i = 0; i < k; i++) {
			memset(chk, 0, sizeof chk);
			if (match(i)) ans++;
		}
		cout << k - ans << '\n';

		for (int i = 0; i < MX; i++) {
			par[i] = -1;
			g[i].clear();
		}
	}
	
	return 0;
}