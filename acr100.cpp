#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

int casos, x, y, cont;
string s, r;

int main() {
	cin >> casos;
	while (casos--) {
		cont = 0;
		cin >> s;
		while (s.size() < 4)
			s.push_back('0');
		if (s[0] == s[1] && s[1] == s[2] && s[2] == s[3])
			cout << 8 << '\n';
		else {
			while (s != "6174") {
				++cont;
				sort(s.begin(), s.end());
				r = s;
				reverse(r.begin(), r.end());
				stringstream intx(s), inty(r);
				intx >> x;
				inty >> y;
				x = y - x;
				s = to_string(x);
				while (s.size() < 4)
					s.push_back('0');
			}
			cout << cont << '\n';
		}
	}
	return 0;
}