#include <bits/stdc++.h>

using namespace std;

bool valid(vector <int> &v, int l, int r)
{
    int i, n = v.size();
    set <int> s, d;

    if (min(l, r) < 0 || max(l, r) >= n) {
        return false;
    }

    swap(v[l], v[r]);
    
    s.insert(v[0]);

    for (i = 1; i < n; i++) {
        if (s.count(v[i]) && v[i] != v[i - 1]) {
            swap(v[l], v[r]);

            return false;
        }

        s.insert(v[i]);
    }

    swap(v[l], v[r]);

    return true;
}

pair <int, int> bound(vector <int> &v, int k, int d)
{
    int i, n = v.size(), l = -1, r = -1;

    if (d == 1) {
        for (i = 0; i < n; i++) {
            if (v[i] == k) {
                if (l == -1) {
                    l = i;
                }
            }
            else if (l != -1) {
                r = i - 1;

                break;
            }
        }

        if (i == n && l != -1) {
            r = n - 1;
        }
    }
    else {
        for (i = n - 1; i >= 0; i--) {
            if (v[i] == k) {
                if (r == -1) {
                    r = i;
                }
            }
            else if (r != -1) {
                l = i + 1;

                break;
            }
        }

        if (i == -1 && r != -1) {
            l = 0;
        }
    }

    return {l, r};
}

void solve()
{
    int n, i;
    set <int> s, d;

    cin >> n;

    vector <int> v(n);

    for (auto &it : v) {
        cin >> it;
    }

    s.insert(v[0]);

    for (i = 1; i < n; i++) {
        if (s.count(v[i]) && v[i] != v[i - 1]) {
            d.insert(v[i]);
        }

        s.insert(v[i]);
    }

    if (d.size() == 0) {
        cout << "YES\n";
    }
    else if (d.size() == 1) {
        auto l = bound(v, *d.begin(), 1);
        auto r = bound(v, *d.begin(), -1);

        if (valid(v, l.first - 1, r.first) || valid(v, l.second + 1, r.first) || valid(v, l.first, r.first - 1) || valid(v, l.first, r.second + 1)) {
            cout << "YES\n";
        }
        else {
            cout << "NO\n";
        }
    }
    else if (d.size() == 2) {
        auto l1 = bound(v, *d.begin(), 1);
        auto r1 = bound(v, *d.begin(), -1);

        d.erase(d.begin());

        auto l2 = bound(v, *d.begin(), 1);
        auto r2 = bound(v, *d.begin(), -1);

        if (valid(v, l1.first - 1, r1.first) || valid(v, l1.second + 1, r1.first) || valid(v, l1.first, r1.first - 1) || valid(v, l1.first, r1.second + 1)) {
            cout << "YES\n";
        }
        else if (valid(v, l2.first - 1, r2.first) || valid(v, l2.second + 1, r2.first) || valid(v, l2.first, r2.first - 1) || valid(v, l2.first, r2.second + 1)) {
            cout << "YES\n";
        }
        else if (valid(v, l1.first, l2.first) || valid(v, l1.first, l2.second) || valid(v, l1.first, r2.first) || valid(v, l1.first, r2.second)) {
            cout << "YES\n";
        }
        else if (valid(v, l1.second, l2.first) || valid(v, l1.second, l2.second) || valid(v, l1.second, r2.first) || valid(v, l1.second, r2.second)) {
            cout << "YES\n";
        }
        else if (valid(v, r1.first, l2.first) || valid(v, r1.first, l2.second) || valid(v, r1.first, r2.first) || valid(v, r1.first, r2.second)) {
            cout << "YES\n";
        }
        else if (valid(v, r1.second, l2.first) || valid(v, r1.second, l2.second) || valid(v, r1.second, r2.first) || valid(v, r1.second, r2.second)) {
            cout << "YES\n";
        }
        else {
            cout << "NO\n";
        }
    }
    else {
        cout << "NO\n";
    }
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