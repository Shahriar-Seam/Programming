#include <bits/stdc++.h>

using namespace std;

void solve()
{
    string s, p;
    int n, m, i, j, k, l;
    int cnt_s = 0, cnt_p = 0;

    cin >> s >> p;

    n = s.size();
    m = p.size();

    if (s[n - 1] != p[m - 1]) {
        cout << "NO\n";

        return;
    }

    for (i = 0, j = 0, k = 0, l = 0; i < n; i++) {
        if (s[i] == s[j]) {
            cnt_s++;
        }
        else {
            cnt_p = 0;

            for (k, l; k < m; k++) {
                if (p[k] == p[l]) {
                    cnt_p++;
                }
                else {
                    break;
                }
            }

            if (s[j] == p[l] && cnt_s * 2 >= cnt_p && cnt_p >= cnt_s) {
                // do nothing
            }
            else {
                cout << "NO\n";

                return;
            }

            cnt_s = 1;
            cnt_p = 0;
            j = i;
            l = k;
        }
    }

    cnt_p = 0;

    for (k, l; k < m; k++) {
        if (p[k] == p[l]) {
            cnt_p++;
        }
        else {
            cout << "NO\n";

            return;
        }
    }

    if (s[j] == p[l] && cnt_s * 2 >= cnt_p && cnt_p >= cnt_s) {
        cout << "YES\n";
    }
    else {
        cout << "NO\n";
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