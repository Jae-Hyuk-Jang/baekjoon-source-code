#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	long long n, ans = 0; cin >> n;
	for (int i = 1; i <= n; i *= 10) ans += (n - i + 1);
	cout << ans;
	return 0;
}