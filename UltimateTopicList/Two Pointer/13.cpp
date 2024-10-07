#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k, l, r, length = 0;
    map <int, int> mp;

    cin >> n >> k;

    vector <int> v(n);

    for (auto &it : v) {
        cin >> it;
    }

    for (l = 0, r = 0; r < n; r++) {
        if (mp.find(v[r]) == mp.end()) {
            mp.insert({v[r], r});
        }
        else {
            if (mp[v[r]] >= l) {
                l = mp[v[r]] + 1;
            }

            mp[v[r]] = r;
        }

        length = max(length, r - l);
    }

    cout << length << "\n";

    return 0;
}