#include <iostream>
#include <vector>

using namespace std;
int k, pot, sol;

int main() {
	vector<long long int> pot4(16);
	pot4[0] = 1;
	for (int i = 1; i < 16; ++i)
		pot4[i] = pot4[i - 1] * 4;
	while (cin >> k) {
		sol = 0;
		pot = 0;
		vector<int> v;
		while (k) {
			v.push_back(k * pot4[pot]);
			++pot;
			k /= 2;
		}
		for (int i = 0; i < v.size(); ++i)
			sol += v[i];
		cout << sol * 4 << '\n';
	}
	return 0;
}