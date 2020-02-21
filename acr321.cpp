#include <iostream>

using namespace std;
int A, N, M, sum;

int main() {
	cin >> A;
	while (A--) {
		cin >> N >> M;
		sum = N + M;
		cout << (sum*sum + sum) / 2 + 1 + N << '\n';
	}
	return 0;
}