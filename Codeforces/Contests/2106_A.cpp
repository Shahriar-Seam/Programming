#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, i, cnt = 0;
    string s;

    cin >> n >> s;

    vector <string> v(n);

    for (i = 0; i < n; i++) {
        string ss = s;
        
        if (ss[i] == '0') {
            ss[i] = '1';
        }
        else {
            ss[i] = '0';
        }

        v.push_back(ss);
    }

    for (auto it : v) {
        cnt += count(it.begin(), it.end(), '1');
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