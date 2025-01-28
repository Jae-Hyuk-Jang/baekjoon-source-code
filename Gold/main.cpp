#include<bits/stdc++.h>
#define MX 1001
using namespace std;

int arr1[MX], arr2[MX];
int N;
int dp1[MX], dp2[MX];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	for (int i = 1; i <= N; i++) {
		int num; cin >> num;
		arr1[i] = arr2[N + 1 - i] = num;
	}
	
	for (int k = 1; k <= N; k++) {
		dp1[k] = dp2[k] = 1;
		for (int i = 1; i <= N; i++) {
			if (arr1[i] < arr1[k]) dp1[k] = max(dp1[k], dp1[i] + 1);
			if (arr2[i] < arr2[k]) dp2[k] = max(dp2[k], dp2[i] + 1);
		}
	}

	int ans = 0;
	for (int i = 1; i <= N; i++) {
		ans = max(ans, dp1[i] + dp2[N + 1 - i]);
	}
	cout << ans -1;
	return 0;
}