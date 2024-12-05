#include<bits/stdc++.h>
using namespace std;


long long mod_pow(int r, const int& i, int m) {
    long long ans = 1;
    for (int j = 0; j < i; j++) ans = ans * r % m;
    return ans % m;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    long long l, m = 1234567891, r = 31, h = 0;
    char c[50];

    cin >> l;
    for (int i = 0; i < l; i++) {
        cin >> c[i];
        c[i] -= 96;
    }

    for (int i = 0; i < l; i++) h += c[i] * mod_pow(r, i, m) % m;

    h %= m;
    cout << h;

    return 0;
}




