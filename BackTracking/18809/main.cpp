#include<bits/stdc++.h>
#define MX 51
using namespace std;
using pii = pair<int, int>;

#define X first
#define Y second

int dx[] = { 1, 0, -1, 0 };
int dy[] = { 0, 1, 0, -1 };

int board[MX][MX];
int n, m, g, r;
int ans, cnt;
vector<pii> cand;
int candsz;

const int EMPTY = 0;
const int GREEN = 1; 
const int  RED = 2;
const int FLOWER = 3;

int brute[10];

int solve() {
	int cnt = 0;
	pii state[MX][MX];
	queue<pii> q;

	for (int i = 0; i < candsz; i++) {
		if (brute[i] == GREEN || brute[i] == RED) {
			state[cand[i].X][cand[i].Y] = { 0, brute[i] };
			q.push(cand[i]);
		}
	}


	while (!q.empty()) {
		auto cur = q.front(); q.pop();
		int curtime = state[cur.X][cur.Y].X;
		int curcolor = state[cur.X][cur.Y].Y;
		if (curcolor == FLOWER) continue;

		for (int dir = 0; dir < 4; dir++) {
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			if (board[nx][ny] == 0) continue;
			if (state[nx][ny].Y == EMPTY) {
				state[nx][ny] = { curtime + 1, curcolor };
				q.push({ nx, ny });
			}
			else if (state[nx][ny].Y == RED) {
				if (curcolor == GREEN && state[nx][ny].X == curtime + 1) {
					cnt++;
					state[nx][ny].Y = FLOWER;
				}
			}
			else if (state[nx][ny].Y == GREEN) {
				if (curcolor == RED && state[nx][ny].X == curtime + 1) {
					cnt++;
					state[nx][ny].Y = FLOWER;
				}
			}
		}
	}
	return cnt;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);


	cin >> n >> m >> g >> r;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
			if (board[i][j] == 2) {
				cand.push_back({ i, j });
			}
		}
	}

	candsz = cand.size();
	fill(brute + candsz - g - r, brute + candsz - r, GREEN);
	fill(brute + candsz - r, brute + candsz, RED);

	int mx = 0;
	do {
		mx = max(mx, solve());
	} while (next_permutation(brute, brute + candsz));
	cout << mx;
	return 0;
}