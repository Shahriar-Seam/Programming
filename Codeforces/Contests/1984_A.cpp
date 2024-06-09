#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, i;

    cin >> n;

    vector <int> v(n);

    for (auto &it : v) {
        cin >> it;
    }

    if (v[0] == v[n - 1]) {
        cout << "NO\n";

        return;
    }

    cout << "YES\n";

    set <int> s(v.begin(), v.end());

    if (s.size() == 2) {
        if (v[0] == v[1]) {
            cout << "B";

            for (i = 1; i < n; i++) {
                cout << "R";
            }
        }
        else {
            for (i = 1; i < n; i++) {
                cout << "R";
            }

            cout << "B";
        }
    }
    else {
        cout << "B";

        for (i = 1; v[i] == v[0]; i++) {
            cout << "B";
        }

        for (i; v[i] != v[n - 1]; i++) {
            cout << "R";
        }

        for (i; i < n; i++) {
            cout << "B";
        }
    }

    cout << "\n";
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