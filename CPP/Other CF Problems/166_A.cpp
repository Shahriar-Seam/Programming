#include <bits/stdc++.h>

using namespace std;

struct point {
    int p, t;

    bool operator < (point pt) {
        return p == pt.p ? t < pt.t : p > pt.p;
    }
};

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k, count = 0, i;

    cin >> n >> k;

    vector <point> v(n);

    for (auto &it : v) {
        cin >> it.p >> it.t;
    }

    sort(v.begin(), v.end());

    for (i = 0; i < n; i++) {
        if (v[i].p == v[k - 1].p && v[i].t == v[k - 1].t) {
            count++;
        }
    }

    cout << count << "\n";

    return 0;
}