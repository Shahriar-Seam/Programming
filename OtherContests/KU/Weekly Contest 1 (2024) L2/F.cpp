#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long n, x, i, count = 0, pref = 0;
    map <long long, long long> mp;

    cin >> n >> x;

    mp[0] = 1;

    vector <long long> v(n);

    for (auto &it : v) {
        cin >> it;
    }

    for (i = 0; i < n; i++) {
        pref += v[i];

        count += mp[pref - x];

        mp[pref]++;
    }

    cout << count << "\n";

    return 0;
}