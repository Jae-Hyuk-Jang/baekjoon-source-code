#include<iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t; cin >> t;
    int mini = 1e9;
    int maxi = -1e9;
    while (t--) {
        int n; cin >> n;
        mini = min(mini, n);
        maxi = max(maxi, n);
    }
    cout << mini << ' ' << maxi;
    return 0; 
}