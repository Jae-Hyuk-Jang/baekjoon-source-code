#include<bits/stdc++.h>
using namespace std;

int sum, temp, result, N, cnt = 0;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N; temp = N;
    while (temp > 0) {
        cnt++;
        temp /= 10;
    }

    for (int i = N - 9 * cnt; i < N; i++) {
        if (i < 0) i = 1;
        sum = 0;
        temp = i;
        while (temp > 0) {
            sum += temp % 10;
            temp /= 10;
        }
        if (i + sum == N) {
            cout << i;
            return 0;
        }
    }
    cout << '0';

    return 0;
}

