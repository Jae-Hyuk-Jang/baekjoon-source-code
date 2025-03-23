#include<bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

bool isPuyo;
bool vis[12][6];
string board[12];

int dy[] = { 1, 0, -1, 0 };
int dx[] = { 0, 1, 0, -1 };

int ans;


void resetVis() {
	for (int i = 0; i < 12; i++) {
		for (int j = 0; j < 6; j++) {
			vis[i][j] = false;
		}
	}
}

void puyo(int x, int y) {
	bool doErase = false;
	vis[x][y] = true;
	char color = board[x][y];
	queue<pii> q;
	vector<pii> tmp;
	q.push({ x, y });
	tmp.push_back({ x, y });

	while (!q.empty()) {
		pii cur = q.front(); q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = cur.first + dx[i];
			int ny = cur.second + dy[i];
			if (nx < 0 || nx >= 12 || ny < 0 || ny >= 6) continue;
			if (vis[nx][ny] || board[nx][ny] == '.' || board[nx][ny] != color) continue;
			vis[nx][ny] = true;
			q.push({ nx, ny }); tmp.push_back({ nx, ny });
		}
	}

	if (tmp.size() >= 4) {
		isPuyo = true;
		for (auto cur : tmp) board[cur.first][cur.second] = '.';
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	for (int i = 0; i < 12; i++) cin >> board[i];

	do {
		isPuyo = false;
		for (int i = 0; i < 6; i++) {
			int idx = -1;
			for (int j = 11; j > -1; j--) {
				if (board[j][i] == '.') idx = max(idx, j);
				if (board[j][i] != '.' && idx != -1) {
					board[idx][i] = board[j][i];
					board[j][i] = '.';
					idx -= 1;
				}
			}
		}

		for (int i = 0; i < 12; i++) {
			for (int j = 0; j < 6; j++) {
				if (!vis[i][j] && board[i][j] != '.') puyo(i, j);
			}
		}
		if (isPuyo) ++ans;
		resetVis();
	} while (isPuyo);
	cout << ans;

	return 0;
}