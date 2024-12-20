#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t; cin >> t;
	for (int i = 0; i < t; i++) {
		int x, y, r, x2, y2, r2; 
		cin >> x >> y >> r >> x2 >> y2 >> r2;

		double d = sqrt(((x - x2) * (x - x2)) + ((y - y2) * (y - y2)));
		double sub = r > r2 ? r - r2 : r2 - r;

		if (d == 0 && r == r2) cout << "-1\n";
		else if (r + r2 == d || sub == d) cout << "1\n";
		else if (sub < d && d < (r + r2)) cout << "2\n";
		else cout << "0\n";
	}

	return 0;
}