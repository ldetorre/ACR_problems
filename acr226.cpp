//Primero calculamos los primos hasta 46340 (raíz de 2^31 - 1) con la función sieve()
//Con eso, dado el número k, calculamos cuantos factores primos tiene y sus respectivas potencias
//Nos da igual qué factores son, nos importa solo cuántos son y a qué número están elevados
//Por último, calculamos el número de parejas posibles con el último bucle (esto es lo más difícil de sacar)

#include <iostream>
#include <vector>
#include <bitset>
#include <climits>
#include <algorithm>
#include <unordered_map>
#include <string>
#include <unordered_set>

using namespace std;

const long long int MAX_PRIME = 46340;
long long int k, aux;

bitset<MAX_PRIME + 1> bs; // #include <bitset>
vector<unsigned int> primes, primesc;      // unsigned int
void sieve()
{
    bs.set();          // De momento, todos son primos
    bs[0] = bs[1] = 0; // El 0 y el 1 no lo son.
    for (unsigned int i = 2; i <= MAX_PRIME; ++i)
    {
        if (bs[i])
        {
            // El actual es primo. Tiramos sus mŽultiplos
            for (unsigned int j = i * i; j <= MAX_PRIME; j += i)
                bs[j] = 0;
            primes.push_back(i);
            primesc.push_back(i * i - 1);
        } // if es primo
    }     // for
} // sieve


int main() {
    sieve();
    unordered_map<long long int, long long int> mapa;
    while (cin >> k) {
        long long int kpri = k;
        unordered_map<long long int, long long int> fact_primos;
        vector<long long int> potencias;
        if (k == 1) cout << 1 << '\n';
        else {
            for (long long int i = 0; i < primes.size() && k>1 && primesc[i] < k; ++i) {
                if (k % primes[i] == 0) {
                    k /= primes[i];
                    if (fact_primos.count(primes[i]))++potencias[fact_primos[primes[i]]];

                    else {
                        fact_primos[primes[i]] = potencias.size();
                        potencias.push_back(1);
                    }
                    --i;
                }
            }
            if (k > 1 && kpri == k) cout << 2 << '\n';
            else {
                if (k > 1) {
                    if (!fact_primos.count(k))
                        potencias.push_back(1);
                    else ++potencias[fact_primos[k]];
                }

                long long int sol = potencias[potencias.size() - 1] + 1;
                if (potencias.size() > 1) {
                    for (int i = potencias.size() - 2; i >= 0; --i) {
                        sol = sol * (3 + 2 * (potencias[i] - 1)) - potencias[i];
                    }
                }
                cout << sol << '\n';
            }
        }
    }
    return 0;
}