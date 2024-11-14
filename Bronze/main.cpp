#include<iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        string s; cin >> s;
        int len = s.size();
        for (int i = 0; i < len; i++) {
            for (int j = 0; j < n; j++) cout << s[i];
        }
        cout << '\n';
    }
    return 0; 
}