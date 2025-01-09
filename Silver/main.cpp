#include<bits/stdc++.h>
#define MX 101
using namespace std;

bool mat[MX][MX];
int N;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	int x = 0, y = 0;
	for (int n = 0; n < N; n++) {
		cin >> x >> y;
		for (int i = x; i < x + 10; i++) {
			for (int j = y; j < y + 10; j++) {
				mat[i][j] = 1;
			}
		}
	}

	int area = 0;
	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			if (mat[i][j]) area += 1;
		}
	}
	cout << area;
	
	return 0;
}