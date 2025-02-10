#include<bits/stdc++.h>
using namespace std;
using ll = long long;

ll a = 0;
int N;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string s; cin >> s;
    N = s.size();

    for (int i = 0; i < N - 1; i++) {
        if (s[i] != s[i + 1]) a++;
    }

    cout << ((a == 1) ? 1 : a / 2 + a % 2);

    return 0;
}



