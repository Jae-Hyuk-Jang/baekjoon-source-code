#include<bits/stdc++.h>
#define MX 10
using namespace std;

int N, M;
int arr[MX];
vector<int> res;
bool check[MX];

void dfs() {
	if (res.size() == M) {
		for (auto a : res) cout << a << ' ';
		cout << '\n';
		return;
	}

	for (int i = 1; i <= N; i++) {
		if (check[i]) continue;
		check[i] = true;
		res.push_back(arr[i]);
		dfs();
		check[i] = false;
		res.pop_back();
	}
}


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;
	for (int i = 1; i <= N; i++) cin >> arr[i];
	sort(arr + 1, arr + 1 + N);

	dfs();

	return 0;
}