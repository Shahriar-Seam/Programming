#include <bits/stdc++.h>

using namespace std;

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, i, j, len = 1;
    map <int, int> mp;

    cin >> n;

    vector <int> v(n);

    for (auto &it : v) {
        cin >> it;
    }

    for (i = 0, j = 0; i < n; i++) {
        if (mp.find(v[i]) == mp.end()) {
            mp[v[i]] = i;

            len = max(len, i - j + 1);
        }
        else {
            len = max(len, i - j);

            j = max(j, mp[v[i]] + 1);

            mp[v[i]] = i;
        }
    }

    len = max(len, i - j);

    cout << len << "\n";

    return 0;
}