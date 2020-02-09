#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;
string cat, eq1, eq2, eqMax;
int equipos, partidos, p1, p2, punMax;
bool empate;

int main() {
	cin >> cat;
	while (cat != "FIN") {
		cin >> eq1;
		equipos = partidos = 0;
		empate = true;
		punMax = -1;
		eqMax = eq1;
		unordered_map<string, int> mapa;
		while (eq1 != "FIN") {
			++partidos;
			cin >> p1 >> eq2 >> p2;
			if (!mapa.count(eq1)) {
				mapa[eq1] = 0;
				++equipos;
			}
			if (!mapa.count(eq2)) {
				mapa[eq2] = 0;
				++equipos;
			}
			if (p1 > p2) {
				mapa[eq1] += 2;
				mapa[eq2] += 1;
			}
			else {
				mapa[eq1] += 1;
				mapa[eq2] += 2;
			}
			if (mapa[eq1] > punMax) {
				punMax = mapa[eq1];
				eqMax = eq1;
				empate = false;
			}
			else if (mapa[eq1] == punMax && eqMax!= eq1) {
				empate = true;
			}
			if (mapa[eq2] > punMax) {
				punMax = mapa[eq2];
				eqMax = eq2;
				empate = false;
			}
			else if (mapa[eq2] == punMax && eqMax != eq2) {
				empate = true;
			}
			cin >> eq1;
		}
		if (empate)
			cout << "EMPATE ";
		else cout << eqMax << ' ';
		cout << equipos * (equipos - 1) - partidos << '\n';
		cin >> cat;
	}
	return 0;
}