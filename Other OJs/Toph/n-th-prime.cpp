#include <bits/stdc++.h>

using namespace std;

#define sz 7400005
vector <int> primes;
vector <bool> marked(sz, false);

void sieve()
{
    int i, j;

    for (i = 3; i * i < sz; i += 2) {
        if (!marked[i]) {
            for (j = i * i; j < sz; j += i + i) {
                marked[j] = true;
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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;

    sieve();

    cin >> n;

    cout << primes[n - 1] << "\n";

    return 0;
}