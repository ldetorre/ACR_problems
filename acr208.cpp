#include <iostream>

using namespace std;
long long int f, b;

int main() {
	cin >> f >> b;
	while (f || b) {
		cout << (f + f - b+2) * (b-1) / 2 << '\n';
		cin >> f >> b;
	}

	return 0;
}