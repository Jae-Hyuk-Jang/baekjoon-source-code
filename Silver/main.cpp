#include<bits/stdc++.h>
using namespace std;

int n, arr[25][25];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}

	vector<int> teams(n);
	fill(teams.begin() + n / 2, teams.end(), 1);

	int ans = 1e9;

	do {
		int diff = 0;
		for (int i = 0; i < n; i++) {
			for (int j = i+1; j < n; j++) {
				if (teams[i] != teams[j]) continue;
				if (teams[i] == 0) diff += (arr[i][j] + arr[j][i]);
				else diff -= (arr[i][j] + arr[j][i]);
			}
		}
		ans = min(ans, abs(diff));
	} while (next_permutation(teams.begin(), teams.end()));

	cout << ans;
	return 0;
}