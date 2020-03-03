#include <iostream>
#include <string>
#include <vector>
#include <math.h>

using namespace std;
string dias[] = { "MARTES", "MIERCOLES", "JUEVES", "VIERNES", "SABADO", "DOMINGO", "EMPATE" };
vector<long long int> semana(6);
long long int mini, maxi, sum;
int posmini, posmaxi;
double EPSILON = 0.000001,aux, med, domingo;

int main() {
	cin >> aux;
	semana[0]=round(100*aux);
	maxi = mini = semana[0];
	posmini = posmaxi = 0;
	sum = semana[0];
	while (semana[0] != -100) {		
		for (int i = 1; i < 6; ++i) {
			cin >> aux;
			semana[i] = (long long int)round(100 * aux);
			sum += semana[i];
			
			if (semana[i] == mini)
				posmini = 6;
			else if (semana[i] < mini) {
				posmini = i;
				mini = semana[i];
			}
			
			if (semana[i] == maxi)
				posmaxi = 6;
			else if (semana[i] > maxi) {
				posmaxi = i;
				maxi = semana[i];
			}
		}
		med = 1.0*sum/6.0;
		domingo = 1.0 * semana[5];
		cout << dias[posmaxi] << ' ' << dias[posmini] << ' ';
		if (domingo > med)
			cout << "SI\n";
		else
			cout << "NO\n";


		cin >> aux;
		semana[0] = round(100 * aux);
		maxi = mini = semana[0];
		posmini = posmaxi = 0;
		sum = semana[0];
	}

	return 0;
}