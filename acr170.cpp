#include <iostream>
#include <math.h>

using namespace std;
int piedras, lado;

int main() {
	cin >> piedras;
	while (piedras) {
		lado = (-1 + sqrt(1 + 8 * piedras)) / 2;
		cout << lado << ' ' << piedras - lado*(lado+1)/2<<'\n';
		cin >> piedras;
	}
	return 0;
}