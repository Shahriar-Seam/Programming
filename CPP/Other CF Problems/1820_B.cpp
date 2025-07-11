#include <bits/stdc++.h>

using namespace std;

#define int long long

void solve()
{
    int i, n, cnt, max_count = 0;
    string s;

    cin >> s;

    if (count(s.begin(), s.end(), '0') == 0) {
        n = s.size();

        cout << n * n << "\n";

        return;
    }

    s += s;

    n = s.size();

    for (i = 0; i < n; ) {
        if (s[i] == '1') {
            cnt = 0;

            while (i < n && s[i] == '1') {
                cnt++;

                i++;
            }

            max_count = max(cnt, max_count);
        }
        else {
            i++;
        }
    }

    cout << ((max_count + 1) / 2) * ((max_count + 2) / 2) << "\n";
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