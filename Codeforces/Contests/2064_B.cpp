#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, i, j, f = 1, l = 1, max_val;
    set <int> s;
    map <int, int> mp;
    vector <pair <int, pair <int, int> > > p;

    cin >> n;

    vector <int> v(n);

    for (auto &it : v) {
        cin >> it;
    }

    for (auto it : v) {
        s.insert(it);
    }

    for (i = 1; i < n; i++) {
        if (v[i] == v[i - 1]) {
            f++;
        }
        else {
            break;
        }
    }

    for (i = n - 1; i > 0; i--) {
        if (v[i] == v[i - 1]) {
            l++;
        }
        else {
            break;
        }
    }

    if (n == 1) {
        cout << 1 << " " << 1 << "\n";
    }
    else {
        max_val = 0;

        for (i = 0, j = 0; i < n; i++) {
            if (mp.find(v[i])) {
                
            }
        }
    }

    sort(p.begin(), p.end(), greater <pair <int, pair <int, int> > > ());

    if (!p.empty()) {
        cout << max_val << "\n";
        for (auto it : p) {
            cout << it.first << " : " << it.second.first << " " << it.second.second << "\n";
        }
    }
    else {
        cout << 0 << "\n";
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int32_t t, i;

    cin >> t;

    for (i = 1; i <= t; i++) {
        cout << "Case " << i << ": ";

        solve();
    }

    return 0;
}