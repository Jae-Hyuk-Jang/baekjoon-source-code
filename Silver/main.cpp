#include <bits/stdc++.h>
#define MX 200001
using namespace std;

int dp[MX][26];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string str; cin >> str;
    int len = str.size();
    for (int i = 0; i < len; i++) {
        dp[i][str[i] - 97]++;
        for (int j = 0; j < 26; j++) {
            dp[i + 1][j] += dp[i][j];
        }
    }

    int q; cin >> q;
    while (q--) {
        char c; int l, r;
        cin >> c >> l >> r;
        if (l == 0) cout << dp[r][c - 97] << '\n';
        else cout << dp[r][c - 97] - dp[l - 1][c - 97] << '\n';
    }


    return 0;
}