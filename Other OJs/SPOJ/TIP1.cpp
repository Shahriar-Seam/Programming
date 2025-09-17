#include <bits/stdc++.h>

using namespace std;

const int sz = 1e7 + 5;
vector <int> phi(sz);
bitset <sz> marked;
vector <pair <int, int> > perm_phi;

bool is_perm(int a, int b)
{
    string s = to_string(a), t = to_string(b);

    sort(s.begin(), s.end());
    sort(t.begin(), t.end());

    return s == t;
}

void sieve_phi()
{
    int i, j;

    for (i = 1; i < sz; i++) {
        phi[i] = i;
    }

    phi[1] = 1;
    marked[1] = true;

    for (i = 2; i < sz; i++) {
        if (!marked[i]) {
            for (j = i; j < sz; j += i) {
                marked[j] = true;

                phi[j] = phi[j] / i * (i - 1);
            }
        }
    }

    for (i = 2; i < sz; i++) {
        if (is_perm(i, phi[i])) {
            perm_phi.push_back({i, phi[i]});
        }
    }
}

void solve()
{
    int m;

    cin >> m;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    sieve_phi();

    int32_t t, i;

    cin >> t;

    for (i = 1; i <= t; i++) {
        // cout << "Case " << i << ": ";

        solve();
    }

    cout << perm_phi.size() << "\n";

    return 0;
}