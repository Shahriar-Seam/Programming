#include <bits/stdc++.h>

using namespace std;

double f(vector <double> &v, double m)
{
    int i;
    double mn = 0, mx = 0, max_sum = 0;

    for (i = 0; i < v.size(); i++) {
        mn += v[i] - m;
        mx += v[i] - m;

        max_sum = max({max_sum, -mn, mx});

        if (mn > 0) {
            mn = 0;
        }

        if (mx < 0) {
            mx = 0;
        }
    }

    return max_sum;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cout << fixed << setprecision(9);

    int n, i;
    double l = 1e9, r = -1e9, m1, m2;

    cin >> n;

    vector <double> v(n);

    for (auto &it : v) {
        cin >> it;

        l = min(l, it);
        r = max(r, it);
    }

    for (i = 0; i < 150; i++) {
        m1 = l + (r - l) / 3;
        m2 = r - (r - l) / 3;

        auto temp1 = f(v, m1);
        auto temp2 = f(v, m2);

        if (temp1 == temp2) {
            l = m1;
            r = m2;
        }
        else if (temp1 < temp2) {
            r = m2;
        }
        else {
            l = m1;
        }
    }

    cout << f(v, r) << "\n";

    return 0;
}