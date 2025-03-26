#include<bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

#define MX 101
#define X first
#define Y second

int dx[] = { 1, 0, -1, 0 };
int dy[] = { 0, 1, 0, -1 };

int board[MX][MX];
int vis[MX][MX];

int ans = 0;


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, l, r; cin >> n >> l >> r;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> board[i][j];
		}
	}

	while (1) {
		bool flag = false;
		for (int i = 0; i < MX; i++) fill(vis[i], vis[i] + MX, 0);
		queue<pii> q;

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {

				if (!vis[i][j]) q.push({ i, j });
				int sum = 0;
				vector<pii> tmp;

				while (!q.empty()) {
					auto cur = q.front(); q.pop();

					for (int dir = 0; dir < 4; dir++) {
						int nx = cur.X + dx[dir];
						int ny = cur.Y + dy[dir];

						if (nx < 0 || nx >= n || ny < 0 || ny >= n)continue;
						int diff = abs(board[cur.X][cur.Y] - board[nx][ny]);

						if (diff >= l && diff <= r) {
							flag = true;
							if (!vis[cur.X][cur.Y]) {
								tmp.push_back({ cur.X, cur.Y });
								sum += board[cur.X][cur.Y];
								vis[cur.X][cur.Y] = 1;
							}

							if (!vis[nx][ny]) {
								tmp.push_back({ nx, ny });
								sum += board[nx][ny];
								vis[nx][ny] = true;
								q.push({ nx, ny });
							}
						}
					}
				}

				for (const auto& c : tmp) {
					board[c.X][c.Y] = sum / tmp.size();
				}
			}
		}
		if (!flag) break;
		ans++;
	}
	cout << ans;

	return 0;
}