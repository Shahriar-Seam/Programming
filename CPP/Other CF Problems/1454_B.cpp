#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, temp, i, unique, f = 0;
    map <int, int> mp;
    vector <int> v;

    cin >> n;

    for (i = 0; i < n; i++) {
        cin >> temp;

        v.push_back(temp);
        mp[temp]++;
    }

    for (auto it : mp) {
        if (it.second == 1) {
            unique = it.first;

            f = 1;

            break;
        }
    }

    if (f == 0) {
        cout << -1 << "\n";

        return;
    }

    for (i = 0; i < n; i++) {
        if (v[i] == unique) {
            cout << i + 1 << "\n";

            return;
        }
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