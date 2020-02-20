#include <iostream>
#include <string>
#include<unordered_map>

using namespace std;
unordered_map<string, int> mapa;
string inih, finh;
int sol, noches, inim, finm;


int main() {
	char aux;
	mapa["22"] = 0;
	mapa["23"] = 1;
	mapa["00"] = 2;
	mapa["01"] = 3;
	mapa["02"] = 4;
	mapa["03"] = 5;
	mapa["04"] = 6;
	mapa["05"] = 7;
	mapa["06"] = 8;
	mapa["07"] = 9;
	mapa["08"] = 10;
	mapa["09"] = 11;
	mapa["10"] = 12;
	cin >> noches;
	while (noches) {
		
		sol = 0;
		while (noches--) {
			inih = finh = "";
			cin >> aux;
			inih +=aux;
			cin >> aux;
			inih += aux;
			cin >> aux;
			cin >> inim;
			
			cin >> aux;

			cin >> aux;
			finh += aux;
			cin >> aux;
			finh += aux;
			cin >> aux;
			cin >> finm;

			sol += 60 * (mapa[finh] - mapa[inih]) + finm - inim;
		}
		if (sol / 60 < 10)
			cout << 0;
		cout << sol / 60<<':';
		if (sol % 60 < 10)
			cout << 0;
		cout << sol % 60 <<'\n';
		cin >> noches;
	}
	return 0;
}