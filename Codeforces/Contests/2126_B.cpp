#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, k, i, j, count = 0;

    cin >> n >> k;

    vector <int> v(n);

    for (auto &it : v) {
        cin >> it;
    }

    for (i = 0; i < n; ) {
        if (v[i] == 0) {
            j = i;

            while (j < n && v[j] == 0) {
                if (j - i == k - 1) {
                    count++;

                    i = j + 2;
                    j = i;
                }
                else {
                    j++;
                }
            }

            i = j + 1;
        }
        else {
            i++;
        }
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