#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, m, queries;

    cin >> n >> m >> queries;

    vector <int> b(m), q(queries);

    for (auto &it : b) {
        cin >> it;
    }

    for (auto &it : q) {
        cin >> it;
    }

    if (m == 1) {
        for (auto k : q) {
            if (b[0] > k) {
                cout << b[0] - 1 << "\n";
            }
            else {
                cout << n - b[0] << "\n";
            }
        }

        return;
    }

    sort(b.begin(), b.end());

    for (auto k : q) {
        if (k > b[m - 1]) {
            cout << n - b[m - 1] << "\n";
        }
        else if (k < b[0]) {
            cout << b[0] - 1 << "\n";
        }
        else {
            auto pos = upper_bound(b.begin(), b.end(), k);
            int t2 = *pos;
            int t1 = *--pos;

            cout << (t2 - t1) / 2 << "\n";
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