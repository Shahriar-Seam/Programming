#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, k, p, x, i, j, f = 0, count = 0;

    cin >> n >> k;

    vector <int> v(n);

    for (auto &it : v) {
        cin >> it;
    }

    cin >> p;

    p--;

    x = v[p];

    i = 0;
    j = n - 1;

    while (i < j) {
        while (i < p && (f ^ v[i]) == x) {
            i++;
        }

        while (j > p && (f ^ v[j]) == x) {
            j--;
        }

        if (i == j) {
            if ((f ^ v[i]) != x) {
                count++;
            }

            break;
        }

        f ^= 1;
        count++;
    }

    cout << count << "\n";
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