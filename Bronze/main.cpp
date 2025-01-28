#include<bits/stdc++.h>
#define MOD 123456789
using namespace std;

int mat[1001][1001];
pair<int,int> arr[1001];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        for (int i = 1; i <= n; i++) arr[i] = { 0, i };
        for (int i = 0; i < n; i++) {
            string s; cin >> s;
            for (int j = 0; j < n; j++) {
                mat[i][j] = s[j] - '0';
                if (i < j && mat[i][j]) {
                    arr[j+1].first++;
                }
            }
        }   
        sort(arr+1, arr + n + 1);
        for (int i = 1; i <= n; i++) cout << arr[i].second << ' ';
        cout << '\n';
    }
    
    return 0;
}

//
//#include <bits/stdc++.h>
//
//using namespace std;
//
//void solve() {
//    int n;
//    cin >> n;
//    vector<string> g(n);
//    for (auto& i : g) {
//        cin >> i;
//    }
//    vector<int> p(n);
//    iota(p.begin(), p.end(), 0);
//    sort(p.begin(), p.end(),
//        [&](int x, int y) {
//            if (g[x][y] == '1') return x < y;
//            else return x > y;
//        });
//    for (auto i : p) cout << i + 1 << " "; cout << '\n';
//}
//
//signed main() {
//    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//    int ttt = 1;
//    cin >> ttt;
//    while (ttt--) {
//        solve();
//    }



