#include<iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, cnt = 0;
    cin >> n;
    n = (~n + 1) ^ n;
    for (int i = 0; i < 32; i++)
        if ((n >> i) & 1) cnt++;
    cout << cnt;

    return 0;
}