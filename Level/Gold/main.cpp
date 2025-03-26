#include<bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

#define MX 101
#define X first
#define Y second

int n;
vector<vector<int>> arr;
int dir[4][2] = { {0, 1}, {0, -1}, {1, 0}, {-1, 0} };
int scores[5] = { 0, 1, 10, 100, 1000 };
vector<int> p[401];

int v[401][401], f[401][401];

void init() {
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= n; j++) {
			v[i][j] = 0;
			f[i][j] = 0;
		}
	}
}

void solve(int idx, vector<int> p[]) {
	init();
	int max = -1, mr = 0, mc = 0, fcnt = 0, cnt = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (arr[i][j] != 0) continue;
			cnt = 0;
			fcnt = 0;
			for (int d = 0; d < 4; d++) {
				int nx = i + dir[d][0];
				int ny = j + dir[d][1];
				if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
				if (arr[nx][ny] == 0) cnt++;
				for (int k = 0; k < 4; k++) {
					if (arr[nx][ny] == p[idx][k]) fcnt++;
				}
			}

			v[i][j] = cnt, f[i][j] = fcnt;

			if (max < fcnt) {
				max = fcnt, mr = i, mc = j;
			}
			else if (max == fcnt) {
				if (v[i][j] > v[mr][mc]) {
					mr = i, mc = j;
				}
				else if (v[i][j] == v[mr][mc]) {
					if (i < mr) {
						mr = i, mc = j;
					}
					else if (i == mr) {
						if (j < mc) {
							mr = i, mc = j;
						}
					}
				}
			}
		}
	}
	arr[mr][mc] = idx;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	arr.resize(n, vector<int>(n, 0));
	int idx, a;

	for (int i = 0; i < n * n; i++) {
		cin >> idx;
		for (int j = 0; j < 4; j++) {
			cin >> a;
			p[idx].push_back(a);
		}
		solve(idx, p);
	}

	int answer = 0, value = 0, cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			value = arr[i][j];
			cnt = 0;
			for (int k = 0; k < 4; k++) {
				int nx = i + dir[k][0];
				int ny = j + dir[k][1];
				if (nx < 0 || nx >= n || ny < 0 || ny >= n)continue;
				for (int z = 0; z < 4; z++) {
					if (arr[nx][ny] == p[value][z]) cnt++;
				}
			}
			answer += scores[cnt];
		}
	}
	cout << answer;


	return 0;
}