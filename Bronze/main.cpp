#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	long long int a, b; cin >> a >> b;
	if (a > b) {
		long long int tmp = b;
		b = a;
		a = tmp;

		cout << b - a - 1 << '\n';
		while (a < b - 1) {
			cout << ++a << ' ';
		}
	}
	else if (a == b) {
		cout << 0;
	}
	else {
		cout << b - a - 1 << '\n';
		while (a < b - 1) {
			cout << ++a << ' ';
		}
	}

	return 0;
}