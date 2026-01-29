#include <bits/stdc++.h>

using namespace std;

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, a, d, sum, i, days = 0;
    map <int, int> mp;

    cin >> n >> m;

    while (m--) {
        cin >> a;

        mp[a]++;
    }

    for (d = 1; d < 1000000; d++) {
        sum = 0;

        for (auto &it : mp) {
            sum += it.second / d;
        }

        if (sum >= n) {
            days = d;
        }
        else {
            break;
        }
    }

    cout << days << "\n";

    return 0;
}