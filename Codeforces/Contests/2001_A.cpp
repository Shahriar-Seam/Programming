#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, max_num = 0;

    cin >> n;

    vector <int> v(n);
    map <int, int> mp;

    for (auto &it : v) {
        cin >> it;
    }

    for (auto it : v) {
        mp[it]++;
    }

    for (auto it : mp) {
        max_num = max(max_num, it.second);
    }

    cout << n - max_num << "\n";
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