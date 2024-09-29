#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int num, maxi, idx;
	num = maxi = idx = 0;

	for (int i = 1; i <= 9; i++) {
		cin >> num;
		if (maxi < num) {
			idx = i;
			maxi = num;
		}
	}
	cout << maxi << '\n' << idx;
    
	return 0;
}