#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;
int des, mod, sol;
char p;
string s, scod;
unordered_set<char> vocales;


int main() {
	vocales.insert('a');
	vocales.insert('e');
	vocales.insert('i');
	vocales.insert('o');
	vocales.insert('u');
	vocales.insert('A');
	vocales.insert('E');
	vocales.insert('I');
	vocales.insert('O');
	vocales.insert('U');
	scod = "";
	mod = (int)('z') - (int)('a') + 1;
	while (scod != "FIN") {
		scod = "";
		cin >> p;
		getline(cin, s);
		sol = 0;
		des = (int)('p') - (int)p;
		if (des < 0)
			des = 26 + des;
		for (int i = 0; i < s.size(); ++i) {
			if (isalpha(s[i]) && s[i] == tolower(s[i])) {
				scod += ('a' + ((int)s[i] + des - (int)('a')) % mod);
			}
			else if (isalpha(s[i]))
				scod += ('A' + ((int)s[i] + des - (int)('A')) % mod);
			if (isalpha(s[i]) && vocales.count(scod[scod.size() - 1]))
				++sol;
		}
		if (scod != "FIN")
			cout << sol << '\n';
	}

	return 0;
}