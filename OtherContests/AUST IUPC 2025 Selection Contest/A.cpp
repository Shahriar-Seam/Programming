#include <bits/stdc++.h>

using namespace std;

#define int long long

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, i, count = 0;
    map <int, int> mp;

    cin >> n;

    vector <int> v(n);

    for (auto &it : v) {
        cin >> it;
    }

    for (i = 0; i < n; i++) {
        v[i] %= 200;
    }

    for (auto it : v) {
        count += mp[it];

        mp[it]++;
    }

    cout << count << "\n";

    return 0;
}