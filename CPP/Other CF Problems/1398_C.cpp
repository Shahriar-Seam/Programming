#include <bits/stdc++.h>

using namespace std;

#define int long long

void solve()
{
    int n, i, sum = 0, count = 0;
    map <int, int> mp;
    string s;

    cin >> n >> s;

    mp[0] = 1;

    for (i = 0; i < n; i++) {
        sum += (s[i] - '0');

        mp[sum - i - 1]++;

        count += mp[sum - i - 1] - 1;
    }

    cout << count << "\n";
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int32_t t, i;

    cin >> t;

    for (i = 1; i <= t; i++) {
        // cout << "Case " << i << ": ";

        solve();
    }

    return 0;
}