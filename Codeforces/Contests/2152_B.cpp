#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, rk, ck, rd, cd, d;

    cin >> n >> rk >> ck >> rd >> cd;

    if (rk == rd || ck == cd) {
        if (rk == rd) {
            if (ck == cd + 1) {
                cout << n + 1 - ck << "\n";

                return;
            }
            else if (ck + 1 == cd) {
                cout << ck + 1 << "\n";

                return;
            }

            if (cd < ck) {
                cout << max(n - ck + rk, n - rk + n - ck) << "\n";

                return;
            }
            else {
                cout << max(ck + rk + 1, n - rk + ck) << "\n";

                return;
            }
        }
        else {
            if (rk == rd + 1) {
                cout << n + 1 - rk << "\n";

                return;
            }
            else if (rk + 1 == rd) {
                cout << rk + 1 << "\n";

                return;
            }

            if (rd < rk) {
                cout << max(n - rk + ck, n - rk + n - ck) << "\n";

                return;
            }
            else {
                cout << max(ck + rk + 1, n - ck + rk) << "\n";

                return;
            }
        }
    }
    
    if (rd > rk && cd > ck) {
        d = ck + rk + 1;
    }
    else if (rd > rk && cd < ck) {
        d = n - ck + rk;
    }
    else if (rd < rk && cd > ck) {
        d = n - rk + ck;
    }
    else {
        d = n - rk + n - ck;
    }

    cout << max(d, 1) << "\n";
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