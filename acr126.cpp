#include<iostream>

using namespace std;
int p, n;

int main() {
	cin >> p >> n;
	while (p>=0 || n>= 0) {
		if (p <= n || (p==1 && n==0))
			cout << "YES\n";
		else cout << "NO\n";
		cin >> p >> n;
	}
	return 0;
}