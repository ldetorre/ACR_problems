#include <iostream>
using namespace std;
int p1x,  p1y,  p2x,  p2y;

int main() {
	cin >> p1x >>  p1y >>  p2x >>  p2y;
	while ( p2x - p1x >= 0 &&  p2y -  p1y >= 0) {
		cout << ( p2x - p1x) * ( p2y -  p1y) << '\n';
		cin >> p1x >>  p1y >>  p2x >>  p2y;
	}
	return 0;
}