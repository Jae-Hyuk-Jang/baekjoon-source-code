#include<bits/stdc++.h>
#define MOD 123456789
using namespace std;

long long dp[31][31];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    dp[0][0] = 0;
    for (int i = 1; i < 31; i++) {
        dp[i][1] = i;
        dp[i][0] = 1;
        dp[i][i] = 1;
    }

    
    for (int i = 2; i < 31; i++) {
        for (int j = 1; j < 31; j++) {
            dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j]) % MOD;
            //cout << dp[i][j] << endl;
        }
    }
    int T; cin >> T;
    while (T--) {
        int n, m; cin >> n >> m;
        cout << dp[m][n] << '\n';
    }
    
    return 0;
}