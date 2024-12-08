#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, k, i, j, f;

    cin >> n >> k;

    vector <int> v(n);

    for (auto &it : v) {
        cin >> it;
    }

    for (i = 0; i < n; i++) {
        f = 1;

        for (j = 0; j < n; j++) {
            if (j != i) {
                if (abs(v[i] - v[j]) % k == 0) {
                    f = 0;

                    break;
                }
            }
        }

        if (f) {
            cout << "YES\n" << i + 1 << "\n";

            return;
        }
    }

    cout << "NO\n";
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