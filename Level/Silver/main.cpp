#include <bits/stdc++.h>
using namespace std;



int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;  cin >> N;

	long long ans = 0;
	for (int i = 1; i <= N; i++) {
		ans += (N / i) * i;
	}
	cout << ans;
	return 0;
}
