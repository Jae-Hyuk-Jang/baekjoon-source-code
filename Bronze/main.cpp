#include<bits/stdc++.h>
using namespace std;

char board[50][50];
int n, m, ans, cnt;

int getCount(int startX, int startY) {
    int turn = 0, temp = n * m;

    for (int start = 1; start <= 2; start++) {
        int count = 0;
        for (int i = startX; i < startX + 8; i++) {
            turn = start;
            for (int j = startY; j < startY + 8; j++) {
                if (turn == 1) {
                    if (board[i][j] != 'W') count++;
                    turn = 2;
                }
                else if (turn == 2) {
                    if (board[i][j] != 'B') count++;
                    turn = 1;
                }
            }
            if (start == 1) start = 2;
            else start = 1;
        } 
        temp = min(temp, count);
    }
    return temp;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    ans = n * m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
        }
    }

    for (int i = 0; i <= n - 8; i++) {
        for (int j = 0; j <= m - 8; j++) {
            cnt = getCount(i, j);
            ans = min(ans, cnt);
        }
    }
    cout << ans;

    return 0;
}







