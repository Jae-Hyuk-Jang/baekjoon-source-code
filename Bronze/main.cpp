#include<bits/stdc++.h>
using namespace std;


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

	long int a, b, c;
	int arr[3];
	while (1)
	{
		cin >> a; arr[0] = a;
		cin >> b; arr[1] = b;
		cin >> c; arr[2] = c;

		sort(arr, arr + 3);
		a = arr[0], b = arr[1], c = arr[2];
		if (a == 0 && b == 0 && c == 0) break;
		else if (((a * a) + (b * b) == (c * c)) && (a > 0 && b > 0 && c > 0))//1 0 1일때의 반례 방지
			cout << "right" << endl;
		else
			cout << "wrong" << endl;

	}
    
    return 0;
}


