#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, i, j, temp;

    cin >> n;

    vector <int> v, frogs(n + 1, 0);
    map <int, int> mp;

    for (i = 0; i < n; i++) {
        cin >> temp;

        mp[temp]++;
    }

    for (auto it : mp) {
        v.push_back(it.first);
    }

    for (i = 0; i < v.size(); i++) {
        for (j = v[i]; j <= n; j += v[i]) {
            frogs[j] += mp[v[i]];
        }
    }

    cout << *max_element(begin(frogs), end(frogs)) << "\n";
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