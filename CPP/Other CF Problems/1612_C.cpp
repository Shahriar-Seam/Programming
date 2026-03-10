#include <bits/stdc++.h>

using namespace std;

#define int long long

int sum_to_n(int n)
{
    return (n * (n + 1)) / 2;
}

int sum_to_n_m(int n, int m)
{
    return sum_to_n(n) - sum_to_n(n - m);
}

void solve()
{
    int k, x, count_up = 0, count_down = 0;
    int l, r, m, p, q;

    cin >> k >> x;

    if (sum_to_n(k) < x) {
        count_up = k;

        x -= sum_to_n(k);

        k--;

        l = 1;
        r = k;
        p = q = 0;

        while (l <= r) {
            m = (l + r) / 2;


            if (sum_to_n_m(k, m) >= x) {
                p = m;

                r = m - 1;
            }
            else {
                q = m;

                l = m + 1;
            }
        }

        count_down = max(p, q);
    }
    else {
        l = 1;
        r = k;
        p = q = 0;

        while (l <= r) {
            m = (l + r) / 2;

            if (sum_to_n(m) >= x) {
                p = m;

                r = m - 1;
            }
            else {
                q = m;

                l = m + 1;
            }
        }

        count_up = max(p, q);
    }

    cout << count_up + count_down << "\n";
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