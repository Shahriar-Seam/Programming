#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, k, i;
    string s, odd, even;

    cin >> n >> k >> s;

    if (k == 0) {
        cout << s << "\n";

        return;
    }

    odd = s;

    for (i = 1; i < n - 1; i++) {
        if (s[i - 1] & s[i + 1] & 1) {
            odd[i] ^= 1;
        }
    }

    if (k == 1) {
        cout << odd << "\n";

        return;
    }

    even = odd;

    for (i = 1; i < n - 1; i++) {
        if (odd[i - 1] & odd[i + 1] & 1) {
            even[i] ^= 1;
        }
    }

    if (k == 2) {
        cout << even << "\n";

        return;
    }

    odd = even;

    for (i = 1; i < n - 1; i++) {
        if (even[i - 1] & even[i + 1] & 1) {
            odd[i] ^= 1;
        }
    }

    cout << (k & 1 ? odd : even) << "\n";
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