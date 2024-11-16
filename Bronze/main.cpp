#include<iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t; cin >> t;
    while (t--) {
        int a, b, result = 1;
        cin >> a >> b;
        while (b--) result = (result * a) % 10;
        cout << ((!result) ? 10 : result) << '\n';
    }
    return 0;
}