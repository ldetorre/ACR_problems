#include <iostream>
#include <math.h>

using namespace std;
int uvas, niveles;

int main() {
	cin >> uvas;
	while (uvas) {
		niveles = (-1 + sqrt(1 + 8 * uvas)) / 2;
		if (niveles * (niveles + 1) == 2*uvas)
			cout << niveles << '\n';
		else cout << niveles + 1 << '\n';
		cin >> uvas;
	}


	return 0;
}