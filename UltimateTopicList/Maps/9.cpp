#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, x, i;
    map <int, int> mp;

    cin >> n >> x;

    vector <int> v(n);

    for (auto &it : v) {
        cin >> it;
    }

    for (i = 0; i < n; i++) {
        if (mp[x - v[i]]) {
            cout << i + 1 << " " << mp[x - v[i]] << "\n";

            return 0;
        }

        mp[v[i]] = i + 1;
    }

    cout << "IMPOSSIBLE\n";

    return 0;
}