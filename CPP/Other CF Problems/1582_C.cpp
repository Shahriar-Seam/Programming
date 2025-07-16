#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, l, r, count, min_count = 1e9;
    char c;
    string s;

    cin >> n >> s;

    for (c = 'a'; c <= 'z'; c++) {
        l = 0;
        r = n - 1;
        count = 0;

        while (l < r) {
            if (s[l] == s[r]) {
                l++;
                r--;
            }
            else if (s[l] == c) {
                l++;
                count++;
            }
            else if (s[r] == c) {
                r--;
                count++;
            }
            else {
                break;
            }
        }

        if (l >= r) {
            min_count = min(min_count, count);
        }
    }

    cout << (min_count == 1e9 ? -1 : min_count) << "\n";
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