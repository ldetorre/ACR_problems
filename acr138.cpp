#include<iostream>

using namespace std;
int casos, num, sol;
long long int aux;

int main() {
	cin >> casos;
	while (casos--) {
		cin >> num;
		sol = 0; 
		aux = 5;
		while (aux <= num) {
			sol += num / aux;
			aux *= 5;
		}
		cout << sol << '\n';
	}
	return 0;
}