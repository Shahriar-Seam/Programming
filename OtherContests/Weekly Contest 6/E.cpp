#include <bits/stdc++.h>

using namespace std;

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, i, sum = 0;
    map <int, int> mp;

    cin >> n;

    vector <int> v(n);

    for (auto &it : v) {
        cin >> it;
    }

    for (i = 0; i < n; i++) {
        if (mp[v[i]] == 0) {
            sum += (2 * sum) - 1;
        }
        else {
            sum++;
        }

        mp[v[i]]++;
    }

    cout << sum << "\n";

    return 0;
}