#include<bits/stdc++.h>
#define MX 10
using namespace std;

int N, M;
int arr[MX];
vector<int> res;

void dfs(int idx, int cnt) {
	if (cnt == M) {
		for (auto a : res) cout << a << ' ';
		cout << '\n';
		return;
	}

	for (int i = idx + 1; i <= N; i++) {
		res.push_back(arr[i]);
		dfs(i, cnt + 1);
		res.pop_back();
	}
}


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;
	for (int i = 1; i <= N; i++) cin >> arr[i];
	sort(arr + 1, arr + 1 + N);

	for (int i = 1; i <= N; i++) {
		res.push_back(arr[i]);
		dfs(i, 1);
		res.pop_back();
	}

	return 0;
}