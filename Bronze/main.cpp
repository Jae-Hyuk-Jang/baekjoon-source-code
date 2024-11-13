#include<iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

	int t; string s;
	cin >> t >> s;
	int sum = 0;
	for (int i = 0; i < t; i++) sum += s[i] - '0';
	cout << sum;
    return 0; 
}