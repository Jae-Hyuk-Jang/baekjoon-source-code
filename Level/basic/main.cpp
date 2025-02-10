#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int T; cin >> T;
	cin.ignore();
	while (T--) {
		string s = "";
		getline(cin, s);
		s+= ' ';
		stack<char> st;
		for (const auto& i : s) {
			if (i == ' ') {
				while (!st.empty()) {
					cout << st.top();
					st.pop();
				}
				cout << i;
			}
			else st.push(i);
		}
	}

	return 0;
}