#include<bits/stdc++.h>
using namespace std;


string sep = "*", p, f;
vector<string> str;


vector<string> split(string& s, string& sep) {
	vector<string> ret;

	int pos = 0;
	while (pos < s.size()) {
		int nxt_pos = s.find(sep, pos);
		if (nxt_pos == -1) nxt_pos = s.size();
		if (nxt_pos - pos > 0) {
			ret.push_back(s.substr(pos, nxt_pos - pos));
		}
		pos = nxt_pos + sep.size();
	}
	return ret;
}

bool solve() {
	cin >> f;
	if (f.size() < str.size() + str[1].size()) return 0;
	if (f.find(str[0]) != 0) return 0;
	int j = f.size() - str[1].size();
	for (const auto& s : str[1]) {
		if (s != f[j++]) return 0;
	}
	return 1;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t; cin >> t;
	cin >> p;
	str = split(p, sep);

	while (t--) {
		cout << ((solve()) ? "DA" : "NE") << '\n';
	}

	return 0;
}