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

    for (auto it : v) {
        mp[it]++;
    }

    for (i = 0; i < n; i++) {
        if (n - i == mp.size()) {
            break;
        }
        else {
            if (mp[v[i]] == 1) {
                mp.erase(v[i]);
            }
            else {
                mp[v[i]]--;
            }
        }
    }

    cout << i << "\n";
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