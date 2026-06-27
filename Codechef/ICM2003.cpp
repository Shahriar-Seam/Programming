#include <bits/stdc++.h>

using namespace std;

const double eps = 1e-8;
const double pi = acos(-1);

double f(double x, double b, double c)
{
    return (x * x + b * x + c) / sin(x);
}

void solve()
{
    double x, b, c;
    double l = eps, r = pi / 2 - eps, m1, m2, d;

    cin >> b >> c;

    while (r - l > eps) {
        m1 = l + (r - l) / 3;
        m2 = r - (r - l) / 3;

        if (f(m1, b, c) < f(m2, b, c)) {
            r = m2;
        }
        else {
            l = m1;
        }
    }

    cout << f(l, b, c) << "\n";
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cout << fixed << setprecision(9);

    int32_t t, i;

    cin >> t;

    for (i = 1; i <= t; i++) {
        // cout << "Case " << i << ": ";

        solve();
    }

    return 0;
}