#include<bits/stdc++.h>
using namespace std;


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

	string str1, str2, str3;
	cin >> str1 >> str2 >> str3;

	auto print = [](int N) {
		if (N % 3 == 0 && N % 5 == 0) cout << "FizzBuzz" << "\n";
		else if (N % 3 == 0) cout << "Fizz" << "\n";
		else if (N % 5 == 0) cout << "Buzz" << "\n";
		else cout << N << "\n";
		};
	if (str3 != "FizzBuzz" && str3 != "Fizz" && str3 != "Buzz") print(stoi(str3) + 1);
	else if (str2 != "FizzBuzz" && str2 != "Fizz" && str2 != "Buzz") print(stoi(str2) + 2);
	else print(stoi(str1) + 3);

    return 0;
}







