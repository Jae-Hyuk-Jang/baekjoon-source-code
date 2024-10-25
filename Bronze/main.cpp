#include<bits/stdc++.h>
using namespace std;

#define MX 1001
double arr[MX];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n; 
	cin >> n;
	for (int i = 0; i < n; i++) cin >> arr[i];
	sort(arr, arr + n);
	double m = arr[n - 1];

	for (int i = 0; i < n; i++) {
		arr[i] = (arr[i] / m) * 100;
	}

	double avg = 0;
	for (int i = 0; i < n; i++) {
		avg += arr[i];
	}
	avg /= n;

	cout.precision(10);
	cout << avg;
    
	return 0;
}