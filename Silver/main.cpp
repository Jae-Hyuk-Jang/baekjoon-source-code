#include <bits/stdc++.h>
#define MX 100001
using namespace std;
typedef long long ll;

int N;
ll arr[MX];
ll dist[MX];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s; cin >> s;
    int ans = 0, sign = 1, num = 0;
    int N = s.size();
    for (int i = 0; i < N; i++) {
        if (s[i] == '+') {
            ans += sign * num;
            num = 0;
        }
        else if (s[i] == '-') {
            ans += sign * num;
            num = 0;
            sign = -1;
        }
        else {
            num = num * 10 + (s[i] - '0');
        }
    }
    ans += sign * num;
    cout << ans;

    return 0;
}