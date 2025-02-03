#include <bits/stdc++.h>

using namespace std;

int max_size = 32000;
vector <int> primes;

void sieve()
{
    int i, j;

    vector <int> marked(max_size, true);

    for (i = 3; i * i < max_size; i += 2) {
        if (marked[i] == true) {
            for (j = i * i; j < max_size; j += i + i) {
                marked[j] = false;
            }
        }
    }

    primes.push_back(2);

    for (i = 3; i < max_size; i += 2) {
        if (marked[i]) {
            primes.push_back(i);
        }
    }
}

int smallest_factor(int n)
{
    for (auto it : primes) {
        if (n % it == 0) {
            return it;
        }
    }

    return n;
}

void solve()
{
    int n, f;

    cin >> n;

    if (n % 2 == 0) {
        cout << n / 2 << " " << n / 2 << "\n";
    }
    else {
        f = smallest_factor(n);

        cout << n / f << " " << n - n / f << "\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    sieve();

    int t;

    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}