#include <bits/stdc++.h>

using namespace std;

#define int long long

typedef struct {
    int a, b, c;
} item;

pair <int, int> closest_val(vector <int> &v, int b)
{
    int l = 0, r = v.size() - 1, mid;
    int m, m_diff = INT_MAX;
    int p = LONG_LONG_MAX, q = LONG_LONG_MAX;

    while (r - l > 10) {
        mid = (r + l) / 2;

        if (v[mid] == b) {
            return {b, b};
        }
        else if (v[mid] < b) {
            l = mid + 1;
        }
        else {
            r = mid - 1;
        }
    }

    for (int i = l; i <= r; i++) {
        if (v[i] < b) {
            p = v[i];
        }
        else {
            q = v[i];

            break;
        }
    }

    if (p == LONG_LONG_MAX) {
        p = q;
    }

    if (q == LONG_LONG_MAX) {
        q = p;
    }

    if (v.front() > b) {
        p = v.front();
        q = v.front();
    }

    if (v.back() < b) {
        p = v.back();
        q = v.back();
    }

    return {p, q};
}

void solve(int t)
{
    int n, m, i, temp, k, f;

    cin >> n >> m;

    set <int> s;
    vector <item> p(m);

    for (i = 0; i < n; i++) {
        cin >> temp;

        s.insert(temp);
    }

    vector <int> v;

    for (auto it : s) {
        v.push_back(it);
    }

    for (i = 0; i < m; i++) {
        cin >> p[i].a >> p[i].b >> p[i].c;
    }

    for (i = 0; i < m; i++) {
        int a = p[i].a, b = p[i].b, c = p[i].c;

        if (c <= 0) {
            cout << "NO\n";

            continue;
        }
    
        auto p = closest_val(v, b);
        int l = p.first;
        int r = p.second;

        k = abs(b - l) < abs(b - r) ? l : r;
    
        if ((b - k) * (b - k) < 4 * a * c) {
            cout << "YES\n" << k << "\n";
        }
        else {
            cout << "NO\n";
        }
    }

    if (t != 0) {
        cout << "\n";
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;

    cin >> t;

    while (t--) {
        solve(t);
    }

    return 0;
}