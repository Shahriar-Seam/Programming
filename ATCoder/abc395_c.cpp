#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, i, min_length = 1e9;
    map <int, int> mp;

    cin >> n;

    vector <int> v(n);

    for (auto &it : v) {
        cin >> it;
    }

    for (i = 0; i < n; i++) {
        if (mp.find(v[i]) != mp.end()) {
            min_length = min(min_length, i - mp[v[i]] + 1);
        }

        mp[v[i]] = i;
    }

    cout << (min_length == 1e9 ? -1 : min_length) << "\n";

    return 0;
}