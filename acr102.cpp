#include <iostream>
#include <vector>

using namespace std;
bool diabolico, esoterico;
int n,d1,d2, cm2;


int main() {
	cin >> n;
	while (n) {
		d1 = d2 = 0;
		diabolico = esoterico = true;
		vector<vector<int>> v(n, vector<int>(n));
		vector<bool> todos(n * n,false);
		vector<int> filas(n,0), columnas(n,0);
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				cin >> v[i][j];
				filas[i] += v[i][j];
				columnas[j] += v[i][j];
				if (v[i][j] - 1 > todos.size() || todos[v[i][j] - 1] == true)
					esoterico = false;
				else todos[v[i][j] - 1] = true;
			}
			d1 += v[i][i];
			d2 += v[i][n - i - 1];
		}
		if (filas[0] != columnas[0] || d1 != d2 || d1 !=filas[0])
			diabolico = false;
		for (int i = 1; i < n && diabolico; ++i) {
			if (filas[i] != filas[i - 1] || columnas[i] != columnas[i - 1])
				diabolico = false;
		}
		if (diabolico && esoterico) {
			cm2 = 4 * d1 / n;
			if (v[0][0] + v[n - 1][0] + v[0][n - 1] + v[n - 1][n - 1] != cm2)
				esoterico = false;
			if (n % 2 == 1) {
				if (v[(n - 1) / 2][(n - 1) / 2] * 4 != cm2)
					esoterico = false;
				if (v[(n - 1) / 2][0] + v[(n - 1) / 2][n - 1] + v[0][(n - 1) / 2] + v[n-1][(n - 1) / 2] != cm2)
					esoterico = false;
			}
			else {
				if (v[(n - 1) / 2][(n - 1) / 2] + v[(n - 1) / 2 + 1][(n - 1) / 2] + v[(n - 1) / 2][(n - 1) / 2 + 1] + v[(n - 1) / 2 + 1][(n - 1) / 2 + 1] != cm2)
					esoterico = false;
				if (v[(n - 1) / 2][0] + v[(n - 1) / 2 + 1][0] + v[0][(n - 1) / 2] + v[0][(n - 1) / 2 + 1] +
					v[(n - 1) / 2][n - 1] + v[(n - 1) / 2 + 1][n - 1] + v[n - 1][(n - 1) / 2] + v[n - 1][(n - 1) / 2 + 1]
					!= 2 * cm2)
					esoterico = false;
			}
			if (esoterico)
				cout << "ESOTERICO\n";
			else cout << "DIABOLICO\n";
		}
		else if (diabolico)
			cout << "DIABOLICO\n";
		else cout << "NO\n";
		cin >> n;
	}
	return 0;
}