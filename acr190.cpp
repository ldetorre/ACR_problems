#include<iostream>

using namespace std;
unsigned long long int num, den, sol;

int main() {
	cin >> num >> den;
	while (num>=den) {
		sol = 1;
		for (unsigned long long int i = den + 1; i <= num; ++i)
			sol *= i;
		cout << sol << '\n';
		cin >> num >> den;
	}
	return 0;
}