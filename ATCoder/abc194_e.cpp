#include <bits/stdc++.h>

using namespace std;

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, i, min_mex = 1e9;
    set <int> missing;
    unordered_map <int, int> mp;

    cin >> n >> m;

    vector <int> v(n);

    for (auto &it : v) {
        cin >> it;
    }

    for (i = 0; i <= n; i++) {
        missing.insert(i);
    }

    for (i = 0; i < m; i++) {
        mp[v[i]]++;

        auto it = missing.find(v[i]);

        if (it != missing.end()) {
            missing.erase(it);
        }
    }

    min_mex = *missing.begin();

    for (i; i < n; i++) {
        mp[v[i]]++;
        mp[v[i - m]]--;
        
        auto it = missing.find(v[i]);

        if (it != missing.end()) {
            missing.erase(it);
        }

        if (mp[v[i - m]] == 0) {
            missing.insert(v[i - m]);
        }

        min_mex = min(min_mex, *missing.begin());
    }

    cout << min_mex << "\n";

    return 0;
}