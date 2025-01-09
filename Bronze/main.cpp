#include <bits/stdc++.h>
#define MX 16
using namespace std;

char c[5][MX];
int arr[5];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string s;
    for (int i = 0; i < 5; i++) {
        cin >> s;
        arr[i] = s.length();
        for (int j = 0; j < arr[i]; j++) {
            c[i][j] = s[j];
        }
    }

    for (int j = 0; j < MX; j++) {
        for (int i = 0; i < 5; i++) {
            if (arr[i] <= j) continue;
            cout << c[i][j];
        }
    }

    return 0;
}


