#include <bits/stdc++.h>

using namespace std;

#define int long long

void solve()
{
    int n, i, neg = 0, pos = 0, bleh = 0;
    map <int, int> mp;
    set <int> s;

    cin >> n;

    vector <int> v(n);

    for (auto &it : v) {
        cin >> it;
    }

    for (auto it : v) {
        mp[it]++;
    }

    for (auto it : mp) {
        if (it.first == -1) {
            neg = it.second;
        }
        else if (it.first == 1) {
            pos = it.second;
        }
        else {
            bleh = it.first;
        }
    }

    for (i = 0; i <= neg; i++) {
        s.insert(-i);
    }

    for (i = 1; i <= pos; i++) {
        s.insert(i);
    }

    for (i = bleh; i < bleh + pos; i++) {
        s.insert(i);
    }

    for (i = bleh; i >= bleh - neg; i--) {
        s.insert(i);
    }

    cout << s.size() << "\n";

    for (auto it : s) {
        cout << it << " ";
    }

    cout << "\n";
}

int32_t main()
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