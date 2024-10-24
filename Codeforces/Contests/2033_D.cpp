#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, i, j = -1, sum = 0, count = 0;
    map <long long, int> mp;

    cin >> n;

    vector <long long> v(n);

    for (auto &it : v) {
        cin >> it;
    }

    mp[0] = -1;

    for (i = 0; i < n; i++) {
        sum += v[i];

        if (mp.find(sum) != mp.end()) {
            if (mp[sum] >= j) {
                count++;

                j = i;
            }
        }

        mp[sum] = i;
    }

    cout << count << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;

    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}