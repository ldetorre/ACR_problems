#include<iostream>

using namespace std;
int casos, num, sol;

int main() {
	cin >> casos;
	while (casos--) {
		cin >> num;
		sol = 0;
		if (num == 0 || num == 1)
			sol = 1;
		else if (num == 2)
			sol = 2;
		else if (num == 3)
			sol = 6;
		else if (num == 4)
			sol = 4;
		cout << sol << '\n';
	}
	return 0;
}