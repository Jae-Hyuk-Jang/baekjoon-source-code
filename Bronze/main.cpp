#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t = 1;
	while (1) {
		int L, P, V; cin >> L >> P >> V;
		if (V == 0)break;
		cout << "Case " << t++ << ": " << V / P * L + min(V % P, L) << '\n';
	}
	return 0;
}