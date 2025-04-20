#include <bits/stdc++.h>
using namespace std;

int dp[1005];
string ans[]{ "SK", "CY" };
int cand[] = { 1, 3, 4 };

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n; cin >> n;
	dp[1] = 0, dp[2] = 1, dp[3] = 0, dp[4] = 0;

	for (int i = 5; i <= n; i++) {
		for (int j : cand) {
			if (dp[i - j] == 1) {
				dp[i] = 0; break;
			}
			else dp[i] = 1;
		}
	}
	cout << ans[dp[n]];
	
	return 0;
}
