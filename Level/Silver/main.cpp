#include <bits/stdc++.h>
#define MX 105
using namespace std;
using ll = long long;


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
    int N; cin >> N;
    while (N--) {
        int num; cin >> num;
        if (num == 0) {
            if (!pq.empty()) {
                cout << pq.top().second << '\n';
                pq.pop();
            }
            else cout << 0 << '\n';
            continue;
        }
        pq.push({ abs(num), num });
    }

    return 0;
}