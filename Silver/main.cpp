#include<bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

    std::function<ll(ll, ll, ll)> POW = [&](ll a, ll b, ll m) -> ll {
        if (b == 1) return a % m;

        ll val = POW(a, b / 2, m);

        val = val * val % m;  

        if (b % 2 == 0) return val;  
        return val * a % m;  
    };
    ll a, b, c; cin >> a >> b >> c;
    cout << POW(a, b, c);

	return 0;
}