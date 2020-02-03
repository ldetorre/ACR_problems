#include <iostream>

using namespace std;
int n,aux;
bool bien;

int main() {
	cin >> n;
	while (n) {
		bien = true;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				cin >> aux;
				if (i != j && aux != 0 || i == j && aux != 1)bien = false;
			}
		}
		if (bien)
			cout << "SI\n";
		else cout << "NO\n";
		cin >> n;
	}

	return 0;
}