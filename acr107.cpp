#include <iostream>
#include <vector>
#include <bitset>
#include <climits>
#include <algorithm>
#include <math.h>
#include <unordered_map>
#include <string>
#include <unordered_set>

using namespace std;

const long long int MAX_PRIME = 100000;
int n, m;
double EPSILON = 0.0000001, eact, emax;
vector<int> v(100001);

bitset<MAX_PRIME + 1> bs; // #include <bitset>
vector<unsigned int> primes;      // unsigned int
void sieve()
{
    bs.set();          // De momento, todos son primos
    bs[0] = bs[1] = 0; // El 0 y el 1 no lo son.
    for (unsigned int i = 2; i <= MAX_PRIME; ++i)
    {
        if (bs[i])
        {
            // El actual es primo. Tiramos sus multiplos
            for (unsigned int j = i * i; j <= MAX_PRIME; j += i)
                bs[j] = 0;
            primes.push_back(i);
        } // if es primo
    }     // for
} // sieve


int main() {
    sieve();
    v[0] = 0;
    for (int i = 1; i < bs.size(); ++i) {
        if (bs[i])
            v[i] = v[i - 1] + 1;
        else v[i] = v[i - 1];
    }
    cin >> n >> m;
    while (n || m) {
        emax = 1.0;
        while (m) {
            emax /= 10.0;
            --m;
        }
        eact = 1.0 * v[n] / (1.0 * n);
        eact -= 1 / (1.0 * log(1.0 * n));
        eact = abs(eact);
        if (eact <= emax + EPSILON && eact >= emax - EPSILON)
            cout << "Igual\n";
        else if (eact > emax)
            cout << "Mayor\n";
        else cout << "Menor\n";
        cin >> n >> m;
    }
    return 0;
}