#include <bits/stdc++.h>

using namespace std;

#define int long long

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, i, j, len = 1, sum = 0;
    map <int, int> mp;

    cin >> n;

    vector <int> v(n);

    for (auto &it : v) {
        cin >> it;
    }

    for (i = 0, j = 0; i < n; i++) {
        if (mp.find(v[i]) == mp.end()) {
            mp[v[i]] = i;

            sum += i - j + 1;
        }
        else {
            j = max(j, mp[v[i]] + 1);
            
            sum += i - j + 1;

            mp[v[i]] = i;
        }
    }

    cout << sum << "\n";

    return 0;
}