#include <bits/stdc++.h>

using namespace std;

#define max_size 1000000

vector <int> primes;
vector <bool> mark(1000002, true);

void sieve()
{
    int i, j, limit = sqrt(max_size * 1.0) + 2;

    mark[0] = mark[1] = false;

    for (i = 4; i <= max_size; i += 2) {
        mark[i] = false;
    }

    primes.push_back(2);

    for (i = 3; i <= max_size; i += 2) {
        if (mark[i] == true) {
            primes.push_back(i);

            if (i <= limit) {
                for (j = i * i; j <= max_size; j += i + i) {
                    mark[j] = false;
                }
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    sieve();

    int i;

    for (i = 0; i < primes.size(); i++) {
        cout << primes[i] << " ";
    }

    return 0;
}