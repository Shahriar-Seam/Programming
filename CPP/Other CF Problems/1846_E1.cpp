#include <bits/stdc++.h>

using namespace std;

#define int long long

const int sz = 1e6 + 5;
bitset <sz> possible;

void pre_calc()
{
    int k, p, kk, sum = 0;

    for (k = 2; k <= 1000; k++) {
        kk = k;
        sum = 1 + k;

        for (p = 0; p <= 20; p++) {
            kk *= k;

            if (sum + kk >= sz) {
                break;
            }
            else {
                sum += kk;

                possible[sum] = 1;
            }
        }
    }
}

void solve()
{
    int n;

    cin >> n;

    cout << (possible[n] ? "YES" : "NO") << "\n";
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    pre_calc();

    int32_t t, i;

    cin >> t;

    for (i = 1; i <= t; i++) {
        // cout << "Case " << i << ": ";

        solve();
    }

    return 0;
}