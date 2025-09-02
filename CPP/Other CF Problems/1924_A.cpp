#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, k, m, i, cnt, index, temp;
    string s, t;

    cin >> n >> k >> m >> s;

    vector <deque <int> > v(k);
    cnt = n;

    for (i = 0; i < m; i++) {
        v[s[i] - 'a'].push_back(i);
    }

    for (i = 0; i < k; i++) {
        v[i].push_back(m);
    }

    while (cnt--) {
        for (i = 0, index = -1, temp = 0; i < k; i++) {
            if (v[i].front() > index) {
                temp = i;
                index = v[i].front();
            }
        }

        if (index == m) {
            cout << "NO\n";

            t += ('a' + temp);

            while (t.size() < n) {
                t += 'a';
            }

            cout << t << "\n";

            return;
        }

        t += ('a' + temp);

        for (i = 0; i < k; i++) {
            while (v[i].front() <= index) {
                v[i].pop_front();
            }
        }
    }

    cout << "YES\n";
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