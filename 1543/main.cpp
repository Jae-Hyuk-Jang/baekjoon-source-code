#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	string og, input;
	int cnt = 0;

	getline(cin, og);
	getline(cin, input);

	for (int i = 0; i < og.length(); i++) {
		bool flag = true;
		for (int j = 0; j < input.length(); j++) {
			if (og[i + j] != input[j]) {
				flag = false;
				break;
			}
		}
		if (flag) {
			cnt++;
			i += input.length() - 1;
		}
	}
	cout << cnt;
	return 0;
}