#include <bits/stdc++.h>

using namespace std;

const int sz = 1e8 + 5;
bitset <sz> marked;
vector <int> primes;

void sieve()
{
    int i, j;

    for (i = 3; i * i < sz; i += 2) {
        if (!marked[i]) {
            for (j = i * i; j < sz; j += 2 * i) {
                marked[j] = 1;
            }
        }
    }

    primes.push_back(2);

    for (i = 3; i < sz; i += 2) {
        if (!marked[i]) {
            primes.push_back(i);
        }
    }
}

int32_t main()
{
    auto start = chrono::high_resolution_clock::now();

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    sieve();

    // for (int i = 0; i < primes.size(); i += 100) {
    //     cout << primes[i] << "\n";
    // }

    auto end = chrono::high_resolution_clock::now();

    chrono::duration <double> duration = end - start;

    cerr << "Time = " << duration.count() << "s\n";

    return 0;
}