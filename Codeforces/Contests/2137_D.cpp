#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, f = 1, i, j = 1, cnt;
    map <int, int> mp;
    map <int, deque <int> > mp_v;

    cin >> n;

    vector <int> v(n);

    for (auto &it : v) {
        cin >> it;

        mp[it]++;
    }

    for (auto &it : mp) {
        if (it.second % it.first != 0) {
            f = 0;
        }
    }

    if (f == 0) {
        cout << "-1\n";

        return;
    }

    j = 1;

    for (auto &it : mp) {
        for (i = 0; i < it.second / it.first; i++) {
            for (int k = 0; k < it.first; k++) {
                mp_v[it.first].push_back(j);
            }

            j++;
        }
    }

    for (auto it : v) {
        cout << mp_v[it].front() << " ";

        mp_v[it].pop_front();
    }

    cout << "\n";
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