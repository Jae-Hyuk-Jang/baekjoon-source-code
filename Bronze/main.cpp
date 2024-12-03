#include<bits/stdc++.h>
using namespace std;

int arr[101];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

	int n = 0, m = 0, sum = 0, result = 0;
	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> arr[i];

	for (int i = 0; i < n - 2; i++) {
		for (int j = i + 1; j < n - 1; j++)
		{
			for (int k = j + 1; k < n; k++) {

				sum = arr[k] + arr[j] + arr[i];
				if (sum <= m && sum > result) {
					result = sum;
				}
			}
		}

	}


	cout << result << '\n';

    return 0;
}


