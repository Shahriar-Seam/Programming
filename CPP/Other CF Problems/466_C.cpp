#include <bits/stdc++.h>

using namespace std;

#define int long long

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, i, sum = 0, total, count = 0;
    map <int, int> mp;

    cin >> n;

    vector <int> v(n);

    for (auto &it : v) {
        cin >> it;

        sum += it;

        mp[sum]++;
    }

    total = sum;

    mp[total]--;

    for (i = 0, sum = 0; i < n - 1; i++) {
        sum += v[i];

        mp[sum]--;

        if (sum * 3 == total) {
            count += max(0LL, mp[2 * sum]);
        }
    }

    cout << count << "\n";

    return 0;
}