#include <bits/stdc++.h>

using namespace std;

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k, i;
    map <int, int> mp;

    cin >> n >> k;

    vector <int> v(n);

    for (auto &it : v) {
        cin >> it;
    }

    for (i = 0; i < k; i++) {
        mp[v[i]]++;
    }

    cout << mp.size() << " ";

    for (i = k; i < n; i++) {
        mp[v[i]]++;
        mp[v[i - k]]--;

        if (!mp[v[i - k]]) {
            mp.erase(v[i - k]);
        }

        cout << mp.size() << " ";
    }

    cout << "\n";

    return 0;
}