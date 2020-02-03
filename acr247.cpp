#include <iostream>

using namespace std;
int n, actual, siguiente;
bool bien;
int main() {
	cin >> n;
	while (n) {
		actual = 0;
		bien = true;
		while (n--) {
			cin >> siguiente;
			if (siguiente > actual)
				actual = siguiente;
			else bien = false;
		}
		if (bien)
			cout << "SI\n";
		else cout << "NO\n";
		cin >> n;
	}
	return 0;
}