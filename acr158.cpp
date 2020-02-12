#include <iostream>

using namespace std;
int ant, act, arriba, abajo, saltos, casos;

int main() {
	cin >> casos;
	while (casos--) {
		cin >> saltos;
		arriba = abajo = 0;
		cin >> ant;
		--saltos;
		while (saltos--) {
			cin >> act;
			if (act > ant)
				++arriba;
			else if (act < ant)
				++abajo;
			ant = act;
		}
		cout << arriba << ' ' << abajo << '\n';
	}
	return 0;
}