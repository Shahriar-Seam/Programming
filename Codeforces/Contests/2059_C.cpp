#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, i, j, k, m = 0, p = 0, f;

    cin >> n;

    vector <vector <int> > v(n, vector <int> (n));
    map <int, int> mp;

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            cin >> v[i][j];
        }
    }

    for (i = 0; i < n; i++) {
        reverse(v[i].begin(), v[i].end());
    }

    sort(v.begin(), v.end());

    for (j = 0; j < n; j++) {
        if (v[0][j] == 1) {
            p++;
        }
        else {
            break;
        }
    }

    for (m = p + 1; m > 0; m--) {
        f = 1;

        for (p = m - 1, i = 0; p >= 0; p--, i++) {
            for (j = 0, k = 0; j < n; j++) {
                if (v[i][j] == 1) {
                    k++;
                }
                else {
                    break;
                }
            }

            if (k < p) {
                f = 0;

                break;
            }
        }

        if (f) {
            cout << m << "\n";

            return;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;

    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}