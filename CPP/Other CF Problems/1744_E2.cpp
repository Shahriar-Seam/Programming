#include <bits/stdc++.h>

using namespace std;

#define int long long

vector <int> get_divisors(int n)
{
    int i;
    vector <int> divs;

    for (i = 1; i * i < n; i++) {
        if (n % i == 0) {
            divs.push_back(i);
            divs.push_back(n / i);
        }
    }

    if (i * i == n) {
        divs.push_back(i);
    }

    return divs;
}

void solve()
{
    int a, b, c, d, ab, x, y, i, j;
    vector <int> d_a, d_b, d_ab;

    cin >> a >> b >> c >> d;

    ab = a * b;

    d_a = get_divisors(a);
    d_b = get_divisors(b);

    for (i = 0; i < d_a.size(); i++) {
        for (j = 0; j < d_b.size(); j++) {
            d_ab.push_back(d_a[i] * d_b[j]);
        }
    }

    for (auto &g : d_ab) {
        x = (a / g + 1) * g;
        y = (b / (ab / g) + 1) * (ab / g);

        if (x <= c && y <= d) {
            cout << x << " " << y << "\n";

            return;
        }
    }

    cout << "-1 -1\n";
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