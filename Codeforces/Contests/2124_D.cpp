#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, k, i, j, mx, l, r, d = 0;

    cin >> n >> k;

    vector <int> v(n), counter(n + 1, 0) , p;

    p.reserve(n);

    for (auto &it : v) {
        cin >> it;

        counter[it]++;
    }
    
    for (i = 0, j = 0; i <= n; i++) {
        j += counter[i];

        if (j >= k) {
            mx = i;
            
            break;
        }
    }

    for (auto &it : v) {
        if (it <= mx) {
            p.emplace_back(it);
        }
    }

    l = 0, r = p.size() - 1;

    while (l < r) {
        if (p[l] == p[r]) {
            l++;
            r--;
        }
        else {
            if (p[l] == mx) {
                l++;
                d++;
            }
            else if (p[r] == mx) {
                r--;
                d++;
            }
            else {
                cout << "NO\n";

                return;
            }
        }
    }

    if (p.size() - d >= k - 1) {
        cout << "YES\n";
    }
    else {
        cout << "NO\n";
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