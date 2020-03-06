#include <iostream>
#include <vector>
#include <string>
#include <math.h>
#include <unordered_map>

using namespace std;
string cat[] = { "DESAYUNOS#","COMIDAS#","MERIENDAS#","CENAS#","COPAS#","EMPATE#" };
double med, aux, EPSILON = 0.00001;
char tipo;
unordered_map<char, int> pos;
long long int maxi, mini, sum;
int posmin, posmax, todo, comidas;

int main() {
	pos['D'] = 1;
	pos['A'] = 2;
	pos['M'] = 3;
	pos['I'] = 4;
	pos['C'] = 5;
	while (cin >> tipo >> aux) {
		vector<long long int> v(5, 0);
		todo = comidas = 0;
		while (tipo != 'N' || round(100 * aux) != 0) {
			v[pos[tipo]-1] += round(100 * aux);
			++todo;
			if (tipo == 'A')
				++comidas;
			cin >> tipo >> aux;
		}
		mini = maxi = v[0];
		sum = v[0];
		posmin = posmax = 0;
		for (int i = 1; i < 5; ++i) {
			sum += v[i];
			if (v[i] == mini)
				posmin = 5;
			else if (v[i] < mini) {
				posmin = i;
				mini = v[i];
			}
			if (v[i] == maxi)
				posmax = 5;
			else if (v[i] > maxi) {
				posmax = i;
				maxi = v[i];
			}
		}
		med = 1.0 * sum / (1.0*todo);
		cout << cat[posmax] << cat[posmin];
		aux = 1.0 * v[1]/(1.0*comidas);
		if (aux > med)
			cout << "SI\n";
		else cout << "NO\n";
	}
	return 0;
}