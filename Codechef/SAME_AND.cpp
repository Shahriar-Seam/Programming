#include <bits/stdc++.h>

using namespace std;

#define int long long

bool test(set <int> &s, int n)
{
    vector <int> v(s.begin(), s.end());
    int i, j;

    for (i = 0; i < v.size(); i++) {
        for (j = i + 1; j < v.size(); j++) {
            if ((v[i] & v[j]) != n) {
                return false;
            }
        }
    }

    return true;
}

void solve()
{
    int n, m, i, j, num;
    set <int> s;
    vector <bool> visited(64, false);

    cin >> n >> m;

    // for (i = 62; i >= 0; i--) {
    //     if ((1LL << i) <= m) {
    //         num = ((1LL << i) | n);

    //         if (num <= m) {
    //             s.insert(num);
    //         }
    //     }
    // }

    s.insert(n);

    for (int bleh = 0; bleh < 1000; bleh++) {
        num = n;

        for (i = 0; i < 63; i++) {
            if (!(n & (1LL << i))) {
                if (!visited[i]) {
                    num |= (1LL << i);
                    visited[i] = true;

                    if (num <= m) {
                        s.insert(num);

                        break;
                    }
                }
            }
        }
    }

    if (s.size() <= 1 || !test(s, n)) {
        cout << -1 << "\n";
    }
    else {
        cout << s.size() << "\n";

        for (auto it : s) {
            cout << it << " ";
        }

        cout << "\n";
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