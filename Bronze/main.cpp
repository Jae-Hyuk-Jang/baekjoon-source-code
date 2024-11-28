#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string n;
    while (1) {
        cin >> n;
        if (n == "0") return 0;

        string tmp = n;
        reverse(tmp.begin(), tmp.end());
        cout << ((tmp == n) ? "yes" : "no") << '\n';
    }
    return 0;
}
