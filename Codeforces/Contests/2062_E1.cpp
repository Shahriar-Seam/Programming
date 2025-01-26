#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, i;

    cin >> n;

    vector <int> v(n);
    vector <vector <int> > g(n - 1, vector <int> (2));
    set <int, greater <int> > s;

    for (auto &it : v) {
        cin >> it;
    }

    for (i = 0; i < n - 1; i++) {
        cin >> g[i][0] >> g[i][1];
    }

    for (i = 1; i < n; i++) {
        s.insert(v[i]);
    }

    for (auto it : s) {
        cout << it << " ";
    }

    cout << "\n";

    if (s.size() == 1 || n == 1) {
        cout << 0 << "\n";

        return;
    }
    

    s.erase(s.begin());

    int w = *s.begin();

    for (i = 1; i < n; i++) {
        if (v[i] == w) {
            cout << i + 1 << "\n";

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