#include <bits/stdc++.h>

using namespace std;

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, d, count = 0;
    map <int, int> mp;

    cin >> n >> d;

    vector <int> v(n);

    for (auto &it : v) {
        cin >> it;

        mp[it]++;
    }

    set <int> s(v.begin(), v.end());

    for (auto &it : s) {
        if (mp[it] > mp[it - d]) {
            count += mp[it - d];

            mp.erase(it - d);
        }
        else {
            count += mp[it];

            mp.erase(it);
        }
    }

    cout << count << "\n";

    return 0;
}