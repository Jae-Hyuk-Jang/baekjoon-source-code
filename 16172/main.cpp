#include <bits/stdc++.h>
using namespace std;

vector<int> failure(string& s) {
    vector<int> f(s.size());
    int j = 0;
    for (int i = 1; i < (int)s.size(); i++) {
        while (j > 0 && s[i] != s[j]) j = f[j - 1];
        if (s[i] == s[j]) f[i] = ++j;
    }
    return f;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s, k;cin >> s >> k;
    vector<int> f = failure(k);

    int j = 0;
    for (int i = 0; i < (int)s.size(); i++) {
        if (s[i] >= '0' && s[i] <= '9') continue;
        while (j > 0 && s[i] != k[j]) j = f[j - 1];
        if (s[i] == k[j]) j++;
        if (j == (int)k.size()) {
            cout << 1;
            return 0;
        }
    }
    cout << 0;
    return 0;
}