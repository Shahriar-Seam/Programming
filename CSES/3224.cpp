#include <bits/stdc++.h>

using namespace std;

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k, i;
    map <int, set <int> > f;
    map <int, int> mp;

    cin >> n >> k;

    vector <int> v(n);

    for (auto &it : v) {
        cin >> it;
    }

    for (i = 0; i < k; i++) {
        mp[v[i]]++;

        if (f.count(mp[v[i]] - 1) && f[mp[v[i]] - 1].count(v[i])) {
            f[mp[v[i]] - 1].erase(v[i]);

            if (f[mp[v[i]] - 1].empty()) {
                f.erase(mp[v[i]] - 1);
            }
        }

        f[mp[v[i]]].insert(v[i]);
    }

    cout << *(*(prev(f.end()))).second.begin() << " ";

    for (i = k; i < n; i++) {
        mp[v[i]]++;
        mp[v[i - k]]--;
        
        if (f.count(mp[v[i]] - 1) && f[mp[v[i]] - 1].count(v[i])) {
            f[mp[v[i]] - 1].erase(v[i]);

            if (f[mp[v[i]] - 1].empty()) {
                f.erase(mp[v[i]] - 1);
            }
        }
        
        if (f.count(mp[v[i - k]] + 1) && f[mp[v[i - k]] + 1].count(v[i - k])) {
            f[mp[v[i - k]] + 1].erase(v[i - k]);

            if (f[mp[v[i - k]] + 1].empty()) {
                f.erase(mp[v[i - k]] + 1);
            }
        }
        
        f[mp[v[i]]].insert(v[i]);
        f[mp[v[i - k]]].insert(v[i - k]);
        
        cout << *(*(prev(f.end()))).second.begin() << " ";
    }

    cout << "\n";

    return 0;
}