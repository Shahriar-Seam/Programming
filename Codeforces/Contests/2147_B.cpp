#include <bits/stdc++.h>

using namespace std;

bool test(vector <int> &v, int n)
{
    vector <int> f(2 * n + 1, 0);
    int i;

    for (i = 1; i <= 2 * n; i++) {
        if (f[v[i]] == 0) {
            f[v[i]] -= i;
        }
        else {
            f[v[i]] += i;

            if (f[v[i]] % v[i] != 0) {
                return false;
            }
        }
    }

    return true;
}

void solve()
{
    int n, i, j, k;

    cin >> n;

    vector <int> v(2 * n + 1, 0);

    for (i = n; i > n / 2; i--) {
        v[2 * i] = i;
        v[i] = i;
    }

    while (i > 0) {
        for (j = 2 * n - 1; j > 0; j--) {
            if (v[j] == 0) {
                for (k = 1; j - k * i > 0; k++) {
                    if (v[j - k * i] == 0) {
                        v[j] = i;
                        v[j - k * i] = i;

                        i--;

                        break;
                    }
                }
            }
        }
    }

    for (i = 1; i <= 2 * n; i++) {
        if (v[i] == 0) {
            v[i] = 1;
        }
    }

    for (i = 1; i <= 2 * n; i++) {
        cout << v[i] << " ";
    }

    cout << "\n";
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