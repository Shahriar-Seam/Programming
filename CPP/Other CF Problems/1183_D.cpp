#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, sum = 0, a, last_taken = 1e9;
    map <int, int> mp;
    vector <int> v;

    cin >> n;

    while (n--) {
        cin >> a;

        mp[a]++;
    }

    for (auto &it : mp) {
        v.push_back(it.second);
    }

    sort(v.begin(), v.end(), greater <> ());

    for (auto &it : v) {
        if (last_taken > it) {
            sum += it;
            last_taken = it;
        }
        else {
            sum += max(0, last_taken - 1);
            last_taken--;
        }
    }

    cout << sum << "\n";
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