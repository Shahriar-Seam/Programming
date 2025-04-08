#include <bits/stdc++.h>

using namespace std;

void solve()
{
    string n;
    int i, f = 0, cnt = 0;

    cin >> n;

    for (i = n.size() - 1; i >= 0; i--) {
        if (!f && n[i] > '0') {
            f = 1;
        }
        else if (!f && n[i] == '0') {
            cnt++;
        }
        else if (f && n[i] > '0') {
            cnt++;
        }
    }

    cout << cnt << "\n";
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