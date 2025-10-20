#include <bits/stdc++.h>

using namespace std;

#define int long long

const int inf = 1e15 + 50;
const int sz = 5;
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

void solve()
{
    int n, i, min_cost = inf;
    map <int, vector <int> > mp, p_m;

    for (auto &it : primes) {
        p_m[it] = {inf, inf};
    }

    cin >> n;

    vector <int> a(n), b(n), temp;

    for (auto &it : a) {
        cin >> it;
    }

    for (auto &it : b) {
        cin >> it;
    }

    temp = a;

    sort(temp.begin(), temp.end());

    for (i = 0; i < n; i++) {
        mp[a[i]].push_back(b[i]);
    }

    for (auto &p : primes) {
        int t = p;

        while (t < sz) {
            auto val = upper_bound(temp.begin(), temp.end(), t);

            if (val != temp.begin()) {
                auto m = mp[*--val];

                auto need = p - ((*--val) % p);

                if (need == p) {
                    need = 0;
                }

                if (m.size() > 1) {
                    if (need <= p_m[p][0]) {
                        p_m[p] = {need, need};
                    }
                    else if (need < p_m[p][1]) {
                        p_m[p][1] = need;
                    }
                }
                else {
                    if (need <= p_m[p][0]) {
                        p_m[p][1] = p_m[p][0];
                        p_m[p][0] = need;
                    }
                    else if (need < p_m[p][1]) {
                        p_m[p][1] = need;
                    }
                }
            }

            cout << t << "\n";

            cout << p_m[2][0] << " " << p_m[2][1] << "\n";

            t = t * p;
        }
    }

    for (auto &it : p_m) {
        min_cost = min(min_cost, it.second[0] + it.second[1]);
    }

    // cout << p_m[2][0] << " " << p_m[2][1] << "\n";

    // cout << min_cost << "\n";
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    sieve();

    int32_t t, i;

    cin >> t;

    for (i = 1; i <= t; i++) {
        // cout << "Case " << i << ": ";

        solve();
    }

    return 0;
}