#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, i, j, k, ans = 0;

    cin >> n;

    vector <int> v(n);

    for (auto &it : v) {
        cin >> it;
    }

    for (i = 0; i < n; i++) {
        if (v[i] > 0) {
            for (j = i + 1; j < n; j++) {
                if (v[j] == 0) {
                    for (k = j + 1; k < n; k++) {
                        if (v[k] > 0) {
                            ans = 2;

                            cout << ans << "\n";

                            return;
                        }
                    }
                }
            }
        }
    }

    if (ans != 2) {
        if (accumulate(v.begin(), v.end(), 0) == 0) {
            ans = 0;
        }
        else {
            ans = 1;
        }
    }

    cout << ans << "\n";
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