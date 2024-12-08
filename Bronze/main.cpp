#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string str;
    int cnt = 0;
    int n; cin >> n;
    for (int title = 666; ; title++) {
        str = to_string(title);
        if (str.find("666") != -1) {
            cnt++;
            if (cnt == n) {
                cout << str;
                return 0;
            }
        }
    }
    
    return 0;
}







