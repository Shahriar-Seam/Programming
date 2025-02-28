#include <bits/stdc++.h>

using namespace std;

#define int long long

void solve()
{
    int n, x, k, p, i, count = 0, moves = 0;
    string s;

    cin >> n >> x >> k >> s;

    p = x;

    for (i = 0; i < min(n, k); i++) {
        if (s[i] == 'L') {
            p--;
        }
        else {
            p++;
        }

        if (p == 0) {
            count++;

            moves = i + 1;

            break;
        }
    }

    // cout << count << " " << "bleh\n";
    // return;

    if (i >= k) {
        cout << count << "\n";
    }
    else if (count == 0) {
        cout << 0 << "\n";
    }
    else {
        count = 1;
        x = 0;

        for (i = 0; i < n; i++) {
            if (s[i] == 'L') {
                x--;
            }
            else {
                x++;
            }

            if (x == 0) {
                break;
            }
        }

        if (i < n) {
            cout << count + (k - moves) / (i + 1) << "\n";
        }
        else {
            cout << count << "\n";
        }
    }
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