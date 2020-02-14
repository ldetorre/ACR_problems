#include <iostream>

using namespace std;
int casos, divisiones, grande, diferencia, sol;


int main() {
	cin >> casos;
	while (casos--) {
		cin >> divisiones >> grande >> diferencia;
		cout << divisiones * ((grande - ((divisiones - 1) * diferencia)) + grande) / 2<<'\n';
	}
	return 0;
}