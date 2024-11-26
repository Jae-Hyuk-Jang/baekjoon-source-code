#include<iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int a, b, c; cin >> a >> b >> c;
    int cnt = 0; int n = b;
    while (n > 0) {
        cnt++;
        n /= 10;
    }
    int mul = 1;
    while (cnt > 0) {
        cnt--;
        mul *= 10;
    }
    cout << a + b - c << '\n';
    cout << a * mul + b - c;
 
	
    return 0;
}

