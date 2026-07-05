#include <bits/stdc++.h>

using namespace std;

#define int long long

struct seg {
    int l, r;
};

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, i = 0, j;
    map <int, int> mp;

    cin >> n;

    vector <seg> v(n);
    vector <int> diff, cnt(n + 1, 0), rev_mp;

    for (auto &it : v) {
        cin >> it.l >> it.r;

        mp[it.l];
        mp[it.r + 1];
    }

    for (auto &it : mp) {
        it.second = i++;

        rev_mp.push_back(it.first);
    }

    diff.assign(mp.size(), 0);

    for (auto &it : v) {
        diff[mp[it.l]]++;
        diff[mp[it.r + 1]]--;
    }

    for (i = 1; i < diff.size(); i++) {
        diff[i] += diff[i - 1];
    }

    for (i = 0, j = 0; j < diff.size(); j++) {
        if (diff[i] != diff[j]) {
            cnt[diff[i]] += rev_mp[j] - rev_mp[i];

            i = j;
        }
    }

    for (i = 1; i <= n; i++) {
        cout << cnt[i] << " ";
    }

    cout << "\n";

    return 0;
}