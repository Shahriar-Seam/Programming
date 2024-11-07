#include <bits/stdc++.h>
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;

typedef struct tree <int, null_type, less <int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

ordered_set s;

#define sz int(27e2 + 5)
vector <bool> marked(sz, true);
vector <int> primes;
vector <int> counter(sz, 0);

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

void fill()
{
    int i, j;

    for (i = 0; i < primes.size(); i++) {
        for (j = primes[i]; j < sz; j += primes[i]) {
            counter[j]++;
        }
    }

    for (i = 0; i < sz; i++) {
        if (counter[i] >= 3) {
            s.insert(i);
        }
    }
}

void solve()
{
    int n;

    cin >> n;

    cout << *s.find_by_order(n - 1) << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    sieve();
    fill();

    int t;

    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}