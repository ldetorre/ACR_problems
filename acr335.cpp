#include <iostream>
#include <vector>

using namespace std;
int casos;
unsigned long long int num, aux;


int main() {
	cin >> casos;
	while (casos--) {
		cin >> num;
		if (num == 1)
			cout << 1 << '\n';
		else {
			if (num % 2 == 0) {
				num /= 2;
				cout << num * (num + 1) * (2 * num + 1) / 3 * 2<<'\n';
			}
			else {
				num /= 2;
				cout << (num + 1) * (2 * num + 1) * (2 * num + 3) / 3 << '\n';
			}
			
		}
	}
	return 0;
}