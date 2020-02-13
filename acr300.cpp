#include <iostream>
#include <unordered_set>
#include <string>

using namespace std;
int casos;
string s;
unordered_set<char> vocales;

int main() {
	vocales.insert('a');
	vocales.insert('e');
	vocales.insert('i');
	vocales.insert('o');
	vocales.insert('u');
	cin >> casos;
	while (casos--) {
		cin >> s;
		unordered_set<char> vocalesPalabra;
		for (int i = 0; i < s.size(); ++i) {
			if (vocales.count(s[i]))
				vocalesPalabra.insert(s[i]);
		}
		if (vocalesPalabra.size() == 5)
			cout << "SI\n";
		else cout << "NO\n";
	}

	return 0;
}