#include <bits/stdc++.h>

using namespace std;

#define int long long

void solve()
{
    int n, sum = 0, count = 0, i, temp = 0;
    map <int, int, greater <> > mp;

    cin >> n;

    vector <int> v(n), odd;

    for (auto &it : v) {
        cin >> it;

        mp[it]++;
    }

    for (auto &it : mp) {
        count += it.second / 2;

        if (it.second & 1) {
            sum += it.first * (it.second - 1);

            odd.push_back(it.first);
        }
        else {
            sum += it.first * it.second;
        }
    }

    count *= 2;

    for (i = 0; i < odd.size(); i++) {
        if (sum > odd[i]) {
            temp = max(temp, odd[i]);
        }
    }

    for (i = 1; i < odd.size(); i++) {
        if (sum + odd[i] > odd[i - 1]) {
            temp = max(temp, odd[i] + odd[i - 1]);
        }
    }

    if (count > 2 || temp > 0) {
        temp += sum;
    }

    cout << temp << "\n";
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