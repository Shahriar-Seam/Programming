#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, i;

    cin >> n;

    vector <int> v(n);
    multiset <int> a, b;

    for (auto &it : v) {
        cin >> it;
    }

    sort(v.begin(), v.end());

    for (i = 0; i < n; i++) {
        if (b.find(v[i]) == b.end()) {
            b.insert(v[i]);
        }
        else if (a.find(v[i]) == a.end()) {
            a.insert(v[i]);
        }
        else {
            while (true) {
                v[i]++;

                if (b.find(v[i]) == b.end()) {
                    b.insert(v[i]);

                    break;
                }
                else if (a.find(v[i]) == a.end()) {
                    a.insert(v[i]);

                    break;
                }
            }
        }
    }

    cout << (a == b ? "YES" : "NO") << "\n";
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