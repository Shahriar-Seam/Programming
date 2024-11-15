#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long n, i, sum1 = 0;
    map <long long, long long> mp;

    cin >> n;

    vector <long long> v(n), pref(n + 1, 0);

    for (auto &it : v) {
        cin >> it;
    }

    for (i = 0; i < n; i++) {
        pref[i + 1] = pref[i] + v[i];
    }

    for (i = 1; i <= n; i++) {
        mp[pref[i]] = i;
    }
    
    for (i = 1; i <= n; i++) {
        if (mp.find(pref[n] - pref[i]) != mp.end()) {
            if (mp[pref[n] - pref[i]] >= i) {
                sum1 = pref[i];
            }
        }
    }

    cout << sum1 << "\n";

    return 0;
}