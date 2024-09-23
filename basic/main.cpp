#include<bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>
#define MX 500001
#define MOD 1000000000
using namespace std;


void parse(string& tmp, deque<int>& d) {
	int cur = 0;
	for (int i = 1; i + 1 < tmp.size(); i++) {
		if (tmp[i] == ',') {
			d.push_back(cur);
			cur = 0;
		}
		else {
			cur = 10 * cur + (tmp[i] - '0');
		}
	}
	if (cur != 0) d.push_back(cur);
}

void print(deque<int>& d) {
	cout << '[';
	for (int i = 0; i < d.size(); i++) {
		cout << d[i];
		if (i + 1 != d.size()) cout << ',';
	}
	cout << "]\n";
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t; cin >> t;
	while (t--) {
		deque<int> dq;
		int rev = 0;
		int n;
		bool isWrong = false;
		string query, tmp;
		cin >> query >> n >> tmp;

		parse(tmp, dq);
		for (auto c : query) {
			if (c == 'R') rev = 1 - rev;
			else {
				if (dq.empty()) {
					isWrong = true;
					break;
				}
				if (!rev) dq.pop_front();
				else dq.pop_back();
			}
		}

		if (isWrong) cout << "error\n";
		else {
			if (rev)  reverse(dq.begin(), dq.end());
			print(dq);
		}
	}
	

	return 0;
}