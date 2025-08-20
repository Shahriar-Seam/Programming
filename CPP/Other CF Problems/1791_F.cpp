#include <bits/stdc++.h>

using namespace std;

int sum(int n, int t)
{
    while (t--) {
        int sum = 0;

        while (n) {
            sum += n % 10;

            n /= 10;
        }

        n = sum;
    }

    return n;
}

void solve()
{
    int n, q, i, op, l, r, x;
    set <int> s;

    cin >> n >> q;

    vector <int> v(n), counter(n + 1, 0);

    for (auto &it : v) {
        cin >> it;
    }

    for (i = 0; i < n; i++) {
        s.insert(i);
    }

    while (q--) {
        cin >> op;

        if (op == 1) {
            cin >> l >> r;

            auto it = s.lower_bound(l - 1);
            vector <int> temp;

            for (it; it != s.end() && *it < r; it++) {
                counter[*it]++;

                if (counter[*it] >= 3) {
                    temp.push_back(*it);
                }
            }

            for (auto &it : temp) {
                s.erase(it);
            }
        }
        else {
            cin >> x;

            cout << sum(v[x - 1], counter[x - 1]) << "\n";
        }
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int32_t t, i;

    cin >> t;

    for (i = 1; i <= t; i++) {
        // cout << "Case " << i << ": ";

        solve();
    }

    return 0;
}