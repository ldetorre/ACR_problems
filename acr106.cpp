#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;
bool ean13, bien;
int aux;
string codigo, pais, s;


int main() {
	unordered_map<string, string> paises;
	paises["0"] = "EEUU";
	paises["380"] = "Bulgaria";
	paises["50"] = "Inglaterra";
	paises["539"] = "Irlanda";
	paises["560"] = "Portugal";
	paises["70"] = "Noruega";
	paises["759"] = "Venezuela";
	paises["850"] = "Cuba";
	paises["890"] = "India";

	cin >> codigo;
	while (codigo.size()>1 || codigo[0] !='0') {
		pais = s = "";
		aux = 0;
		bien = false;
		ean13 = false;
		if (codigo.size() > 8)
			ean13 = true;
		if (ean13) {
			while (s.size() + codigo.size() < 13)
				s += '0';
			s += codigo;
			for (int i = 11; i > 0; i = i - 2)
				aux += 3 * ((int)s[i] - (int)('0'));
			aux += ((int)s[10] + (int)s[8] + (int)s[6] +(int)s[4] +(int)s[2] +(int)s[0] - 6 * (int)('0'));
			if ((10 - (aux % 10)) % 10 == (int)s[12]-int('0'))
				bien = true;
			if (bien) {
				cout << "SI ";
				pais = s[0];
				if (paises.count(pais))
					cout << paises[pais] << '\n';
				else if (paises.count(pais + s[1]))
					cout << paises[pais + s[1]] << '\n';
				else if (paises.count(pais + s[1] + s[2]))
					cout << paises[pais + s[1] + s[2]] << '\n';

				else cout << "Desconocido\n";
			}
			else cout << "NO\n";
			

		}
		else {
			while (s.size() + codigo.size() < 8)
				s += '0';
			s += codigo;
			for (int i = 6; i >= 0; i = i - 2)
				aux += 3 * ((int)s[i] - (int)('0'));
			aux += ((int)s[5] + (int)s[3] + (int)s[1] - 3 * (int)('0'));
			if ((10 - (aux % 10)) % 10 == (int)s[7]-(int)('0'))
				bien = true;
			if (bien)
				cout << "SI\n";
			else cout << "NO\n";
		}


		cin >> codigo;
	}
	return 0;
}