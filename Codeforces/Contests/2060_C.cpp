#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, k, score = 0;
    map <int, int> mp;

    cin >> n >> k;

    vector <int> v(n);

    for (auto &it : v) {
        cin >> it;
    }

    for (auto it : v) {
        mp[it]++;
    }

    for (auto it : mp) {
        if (mp.find(k - it.first) != mp.end()) {
            score += min(it.second, mp[k - it.first]);
        }
    }

    cout << score / 2 << "\n";
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