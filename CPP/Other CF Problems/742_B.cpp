#include <bits/stdc++.h>

using namespace std;

#define int long long

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, x, pairs = 0;
    map <int, int> mp;

    cin >> n >> x;

    vector <int> v(n);

    for (auto &it : v) {
        cin >> it;

        mp[it]++;
    }

    for (auto it : mp) {
        if (mp.find(it.first ^ x) != mp.end()) {
            if (it.first != (it.first ^ x)) {
                pairs += mp[it.first ^ x] * mp[it.first];
            }
            else {
                pairs += mp[it.first ^ x] * (mp[it.first] - 1);
            }
        }
    }

    cout << pairs / 2 << "\n";

    return 0;
}