#include <bits/stdc++.h>

using namespace std;

#define int long long

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q, b, c, sum = 0;
    map <int, int> mp;

    cin >> n;

    vector <int> v(n);

    for (auto &it : v) {
        cin >> it;
    }

    for (auto it : v) {
        mp[it]++;
    }

    for (auto it : mp) {
        sum += (it.first * it.second);
    }

    cin >> q;

    while (q--) {
        cin >> b >> c;
        
        sum -= b * mp[b];
        sum += c * mp[b];

        mp[c] += mp[b];

        mp.erase(b);

        cout << sum << "\n";
    }

    return 0;
}