#include <bits/stdc++.h>

using namespace std;

#define int long long

bool possible(vector <int> &v, int m, int k)
{
    int i, count = 1, d = v[0] + 2 * m;

    for (i = 1; i < v.size(); i++) {
        if (v[i] <= d) {
            // do nothing
        }
        else {
            d = v[i] + 2 * m;

            count++;
        }
    }

    return count <= k;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("angry.in", "r", stdin);
    freopen("angry.out", "w", stdout);

    int n, k;
    int l, r, m, R;

    cin >> n >> k;

    vector <int> v(n);

    for (auto &it : v) {
        cin >> it;
    }

    sort(v.begin(), v.end());

    l = 0, r = 1e10;

    while (l <= r) {
        m = (l + r) / 2;

        if (possible(v, m, k)) {
            r = m - 1;
            R = m;
        }
        else {
            l = m + 1;
        }
    }

    cout << R << "\n";

    return 0;
}