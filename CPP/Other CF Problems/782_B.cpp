#include <bits/stdc++.h>

using namespace std;

bool possible(vector <int> &x, vector <int> &v, double m)
{
    double l = -4e9, r = 4e9;
    int i;

    for (i = 0; i < x.size(); i++) {
        l = max(l, x[i] - m * v[i]);
        r = min(r, x[i] + m * v[i]);
    }

    return (l < r) || (abs(r - l) <= 1e-9);
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cout << fixed << setprecision(8);

    int n, i;
    double l, r, m, t;

    cin >> n;

    vector <int> x(n), v(n);

    for (i = 0; i < n; i++) {
        cin >> x[i] >> v[i];
    }

    l = 0, r = 1e9 + 50;

    for (i = 0; i < 100; i++) {
        m = (l + r) / 2;

        if (possible(x, v, m)) {
            t = m;

            r = m;
        }
        else {
            l = m;
        }
    }

    cout << t << "\n";

    return 0;
}