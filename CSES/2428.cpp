#include <bits/stdc++.h>

using namespace std;

#define int long long

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k, i, j, count = 0;
    map <int, int> mp;

    cin >> n >> k;

    vector <int> v(n);

    for (auto &it : v) {
        cin >> it;
    }

    for (i = 0, j = 0; i < n; i++) {
        mp[v[i]]++;

        if (mp.size() > k) {
            while (mp.size() > k) {
                mp[v[j++]]--;

                if (mp[v[j - 1]] == 0) {
                    mp.erase(v[j - 1]);
                }
            }
        }

        count += (i - j + 1);
    }

    cout << count << "\n";

    return 0;
}