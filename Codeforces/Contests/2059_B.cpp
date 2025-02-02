#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, k, i;

    cin >> n >> k;

    vector <int> v(n), b;

    for (auto &it : v) {
        cin >> it;
    }

    if (n == k) {
        for (i = 1; i < n; i += 2) {
            b.push_back(v[i]);
        }

        for (i = 0; i < b.size(); i++) {
            if (b[i] != i + 1) {
                cout << i + 1 << "\n";

                return;
            }
        }

        cout << b.size() + 1 << "\n";

        return;
    }

    i = 1;

    while (v[i] == 1) {
        i++;
    }

    if ((i <= n - k + 1) && (i < n && v[i] > 1)) {
        cout << 1 << "\n";
    }
    else {
        cout << 2 << "\n";
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