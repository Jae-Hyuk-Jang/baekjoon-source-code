#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    double score = 0.0;
    string str; cin >> str;
    if (str == "F") score = 0.0;
    if (str[0] == 'A') score += 4.0;
    if (str[0] == 'B') score += 3.0;
    if (str[0] == 'C') score += 2.0;
    if (str[0] == 'D') score += 1.0;

    if (str[1] == '+') score += 0.3;
    if (str[1] == '-') score -= 0.3;

    cout.precision(1);
    cout << fixed;
    cout << score;

    return 0;
}



