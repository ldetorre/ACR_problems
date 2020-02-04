#include <iostream>

using namespace std;
int casos, ini, cambio;

int main() {
	cin >> casos;
	while (casos--) {
		cin >> ini >> cambio;
		if (ini + cambio >= 0)
			cout << "SI\n";
		else cout << "NO\n";

	}
	return 0;
}