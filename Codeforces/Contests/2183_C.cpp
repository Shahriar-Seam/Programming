#include <bits/stdc++.h>

using namespace std;

#define int long long

void solve()
{
    int n, m, k, r, l, L, R;
    int current, inc = 1, count = 2;

    cin >> n >> m >> k;

    vector <int> v(n + 1, 0);

    L = k - 1;
    R = n - k;

    if (L == 0) {
        l = 1e9;
        r = 1;

        count = 1;
        current = 1;
    }
    else if (R == 0) {
        l = 1;
        r = 1e9;

        count = 1;
        current = 0;
    }
    else if (L < R) {
        l = 1;
        r = 2;

        current = 0;
        m--;
    }
    else {
        l = 2;
        r = 1;

        current = 1;
        m--;
    }

    while (L > 0 && R > 0 && m > 0) {
        if (current == 0) {
            if (m >= l) {
                m -= l;

                count++;

                L--;
            }
            else {
                break;
            }

            current = 1;
            l++;
        }
        else {
            if (m >= r) {
                m -= r;

                count++;

                R--;
            }
            else {
                break;
            }

            current = 0;
            r++;
        }
    }

    while (L > 0 && m > 0) {
        if (m >= l) {
            m -= l;

            count++;

            L--;
        }
        else {
            break;
        }

        l++;
    }

    while (R > 0 && m > 0) {
        if (m >= r) {
            m -= r;

            count++;

            R--;
        }
        else {
            break;
        }

        r++;
    }

    cout << l << " " << r << " " << m << " " << count << "\n";
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