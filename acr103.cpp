#include <iostream>
#include <vector>

using namespace std;
int grado, rectangulos;
double act, salto, cain, f, x;
double EPSILON = 0.000001;

int main() {
	cin >> grado;
	while (grado != 20) {
		vector<int> v(grado + 1);
		for (int i = 0; i <= grado; ++i) {
			cin >> v[grado - i];
		}
		cin >> rectangulos;
		act = cain = 0.0;
		salto = 1.0 * 1 / (1.0 * rectangulos);
		act = salto;
		while (act < 1.0-EPSILON) {
			f = 1.0*v[0];
			x = act;
			for (int i = 1; i < v.size(); ++i) {
				f += 1.0 * v[i] * x;
				x *= act;
			}
			act += salto;
			if (EPSILON < f && f < 1.0) {
				cain += salto * f;
			}
			else if (f> 1.0-EPSILON) {
				cain += salto;
			}
		}
		if (1 - 2 * cain > 0.002-EPSILON)
			cout << "ABEL\n";
		else if (2 * cain - 1 > 0.002-EPSILON)
			cout << "CAIN\n";
		else cout << "JUSTO\n";
		cin >> grado;
	}
	return 0;
}