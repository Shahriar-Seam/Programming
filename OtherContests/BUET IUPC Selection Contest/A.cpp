#include <bits/stdc++.h>

using namespace std;

#define sz int(1e7 + 1000)
vector <bool> marked(sz + 5, false);
vector <int> primes;

void sieve()
{
    int i, j;

    marked[0] = marked[1] = true;

    for (i = 4; i <= sz; i += 2) {
        marked[i] = true;
    }

    for (i = 3; i * i <= sz; i += 2) {
        if (!marked[i]) {
            for (j = i * i; j <= sz; j += i + i) {
                marked[j] = true;
            }
        }
    }

    primes.push_back(2);

    for (i = 3; i <= sz; i += 2) {
        if (!marked[i]) {
            primes.push_back(i);
        }
    }
}

void solve()
{
    int n, cnt = 0;

    cin >> n;

    int i = lower_bound(primes.begin(), primes.end(), n) - primes.begin();

    for (i = i - 1; i >= 0; i--) {
        if (primes[i] < n - primes[i] || n - primes[i] < 0) {
            break;
        }
        if (!marked[n - primes[i]]) {
            cnt++;
        }

    }

    cout << cnt << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    sieve();

    int t, i;

    cin >> t;

    for (i = 1; i <= t; i++) {
        cout << "Case " << i << ": ";

        solve();
    }

    return 0;
}