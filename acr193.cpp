#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;
string s, r;
int x, y, z;
bool reversible;

int main() {
	cin >> s;
	while (s != "0") {
		reversible = true;
		if (s[s.size() - 1] == '0')
			reversible = false;
		else {
			r = s;
			reverse(r.begin(), r.end());
			stringstream intx(s), inty(r);
			intx >> x;
			inty >> y;
			z = x + y;
			s = to_string(z);
			for (int i = 0; i < s.size() && reversible; ++i)
				if ((int(s[i]) - int('0')) % 2 == 0) reversible = false;
		}
		if (reversible)
			cout << "SI\n";
		else cout << "NO\n";
		cin >> s;
	}

	return 0;
}