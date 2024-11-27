#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    while (n--) {
        string s; cin >> s;
        int len = s.length();
        int ans = 0; int sum = 0;
        for (int i = 0; i < len; i++) {
            if (s[i] == 'O') ans += (++sum);
            else sum = 0;
        }
        cout << ans << '\n';
    }
    return 0;
}

