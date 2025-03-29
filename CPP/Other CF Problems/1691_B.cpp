#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, i;
    map <int, queue <int> > mp;

    cin >> n;

    vector <int> v(n);

    for (auto &it : v) {
        cin >> it;
    }

    for (i = 0; i < n; i++) {
        mp[v[i]].push(i + 1);
    }

    for (auto &it : mp) {
        if (it.second.size() == 1) {
            cout << -1 << "\n";

            return;
        }

        it.second.push(it.second.front());
        it.second.pop();
    }

    for (i = 0; i < n; i++) {
        cout << mp[v[i]].front() << " ";
       
        mp[v[i]].pop();
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