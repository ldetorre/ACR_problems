#include <iostream>
#include <string>
#include <stdio.h>
#include <ctype.h>

using namespace std;
string s;
int letras, exclamaciones;

int main() {
	while(getline(cin,s)) {
		exclamaciones = letras = 0;
		for (int i = 0; i<s.size(); ++i) {
			if (s[i] == '!')
				++exclamaciones;
			else if (isalpha(s[i]))
				++letras;
		}
		if (exclamaciones > letras)
			cout << "ESGRITO\n";
		else cout << "escrito\n";

	}


	return 0;
}