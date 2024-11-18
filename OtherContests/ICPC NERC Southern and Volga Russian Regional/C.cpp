#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, i;
    map <int, int> mp;

    cin >> n;

    vector <int> v(n);

    for (auto &it : v) {
        cin >> it;
    }

    for (i = 0; i < n; i++) {
        mp[v[i]]++;
    }

    v.clear();

    for (auto it : mp) {
        if (it.second >= 2) {
            int temp = it.second / 2;

            for (i = 0; i < temp; i++) {
                v.push_back(it.first);
            }
        }
    }

    if (v.size() >= 4) {
        cout << "YES\n";
        cout << v[0] << " " << v[1] << " " << v[0] << " " << v[v.size() - 1] << " ";
        cout << v[v.size() - 2] << " " << v[1] << " " << v[v.size() - 2] << " " << v[v.size() - 1] << "\n";
    }
    else {
        cout << "NO\n";
    }
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