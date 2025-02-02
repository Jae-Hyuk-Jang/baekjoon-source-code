#include<bits/stdc++.h>
#define MX 105
using namespace std;

struct item { int w, v; };
item x[MX];
int N, K;
int dp[MX][100001];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> K;
	for (int i = 1; i <= N; i++) {
		int w, v; cin >> w >> v;
		x[i] = { w, v };
	}
	
	for (int i = 0; i <= N; i++) dp[i][0] = 0;
	for (int i = 0; i <= K; i++) dp[0][i] = 0;

	for (int i = 1; i <= N; i++) {
		for (int k = 1; k <= K; k++) {
			dp[i][k] = dp[i - 1][k];
			if (k - x[i].w >= 0) dp[i][k] = max(dp[i - 1][k - x[i].w] + x[i].v, dp[i][k]);
		}
	}
	cout << dp[N][K];
	return 0;
}