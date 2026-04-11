#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, m, i, one = 0;

    cin >> n;

    m = n;

    for (i = 0; i < 30; i++) {
        if ((n & (1 << i)) && (!(n & (1 << (i + 1))))) {
            m |= 1 << (i + 1);
            m &= ~(1 << i);

            break;
        }
        else if (n & (1 << i)) {
            m &= ~(1 << i);
            one++;
        }
    }

    for (i = 0; i < one; i++) {
        m |= 1 << i;
    }

    cout << m << "\n";
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int32_t t, i;

    cin >> t;

    for (i = 1; i <= t; i++) {
        cout << "Case " << i << ": ";

        solve();
    }

    return 0;
}