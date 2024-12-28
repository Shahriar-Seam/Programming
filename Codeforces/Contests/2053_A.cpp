#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, i, f = 0;

    cin >> n;

    vector <int> v(n);

    for (auto &it : v) {
        cin >> it;
    }

    for (i = 0; i < n - 1; i++) {
        if ((v[i] >= v[i + 1] && v[i] < 2 * v[i + 1]) || (v[i] <= v[i + 1] && v[i + 1] < 2 * v[i])) {
            f = 1;
            break;
        }
    }

    if (f) {
        cout << "YES\n";
    }
    else {
        cout << "NO\n";
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