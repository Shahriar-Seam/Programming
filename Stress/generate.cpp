#include <bits/stdc++.h>

using namespace std;

#define sz int(1e6 + 5)
vector <bool> marked(sz, true);
vector <int> primes;

void sieve()
{
    int i, j;

    for (i = 3; i * i < sz; i += 2) {
        if (marked[i]) {
            for (j = i * i; j < sz; j += 2 * i) {
                marked[j] = false;
            }
        }
    }

    primes.push_back(2);

    for (i = 3; i < sz; i += 2) {
        if (marked[i]) {
            primes.push_back(i);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // freopen("C:/Users/Anonymous_HF/Desktop/Programming/input.txt", "w", stdout);

    // sieve();

    srand(time(0));

    int t = 10;

    cout << t << "\n";

    for (int i = 0; i < t; i++) {
        int n = rand() % 10 + 1;
        // int q = rand() % 10 + 1;
        // int x = primes[rand() % 500 + 2];

        cout << n << "\n";

        // cout << (long long) (1LL * rand() * 213456) % (long long) 1e15;
        // cout << n << "\n";
        while (n--) {
            cout << rand() % 100 + 1 << " ";
        }

        cout << "\n";
    }

    return 0;
}