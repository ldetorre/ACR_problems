#include <iostream>

using namespace std;
bool equilibrio;

int recursion(int pi, int di, int pd, int dd, bool& eq) {
	int a1, a2, a3, a4;
	if (pi==0) {
		cin >> a1 >> a2 >> a3 >> a4;
		pi = recursion(a1, a2, a3, a4,eq);
	}
	di *= pi;
	if (pd == 0) {
		cin >> a1 >> a2 >> a3 >> a4;
		pd = recursion(a1, a2, a3, a4, eq);
	}
	dd *= pd;
	if (di != dd) {
		eq = false;
	}
	return pi + pd;
}


int main() {
	int pi, di, pd, dd;
	cin >> pi >> di >> pd >> dd;
	while (pi || di || pd || dd) {
		equilibrio = true;
		recursion(pi, di, pd, dd, equilibrio);
		if (equilibrio)
			cout << "SI\n";
		else cout << "NO\n";
		cin >> pi >> di >> pd >> dd;
	}
	return 0;
}