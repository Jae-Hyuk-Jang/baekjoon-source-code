#include<bits/stdc++.h>
using namespace std;

#define MX 1000000
bool nums[MX+1];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	fill(nums + 1, nums + MX + 1, true);
	nums[0] = nums[1] = 0;
	for (int i = 2; i*i <= MX; i++) {
		if (nums[i]) {
			for (int k = i * i; k <= MX; k += i) {
				nums[k] = false;
			}
		}
	}

	int m, n; cin >> m >> n;
	for (int i = m; i <= n; i++) {
		if (nums[i]) cout << i << '\n';
	}


	return 0;
}