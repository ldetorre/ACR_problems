#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int numPlanetas, planeta;
int primos[] = { 2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67 };
vector<vector<int>> v(70,vector<int>(19,0));

int main() {
	int aux;
	for (int i = 0; i < v.size(); ++i) {
		aux = i + 1;
		for (int j = 0; j < 19; ++j) {
			if (aux % primos[j] == 0) {
				v[i][j]++;
				aux /= primos[j];
				--j;
			}
		}
	}
	cin >> numPlanetas;
	int res;
	while (numPlanetas) {
		res = 1;
		vector<int> sol(19,0);
		int i1 = 0, i2 = 0;
		while (numPlanetas--) {
			cin >> planeta;
			for (int i = 0; i < 19; ++i) {
				sol[i] = max(sol[i], v[planeta - 1][i]);
			}
		}
		for (int i = 0; i < sol.size(); ++i) {
			if (sol[i]) {
				res *= primos[i];
				--sol[i];
				--i;
			}
		}
		cout << res << '\n';
		cin >> numPlanetas;
	}
	return 0;
}