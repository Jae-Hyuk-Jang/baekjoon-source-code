#include<bits/stdc++.h>
using namespace std;

const int MOD = 10007;
const int MX = 1002;

int combi[MX][MX];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	for (int i = 1; i <= 1000; i++) {
		combi[i][0] = combi[i][i] = 1;
		for (int j = 1; j < i; j++) {
			combi[i][j] = (combi[i - 1][j - 1] + combi[i - 1][j]) % MOD;
		}
	}
	int n, m; cin >> n >> m;
	cout << combi[n][m];

	return 0;
}