#include <bits/stdc++.h>

using namespace std;

#define int long long

const int sz = 1e5 + 5;
vector <vector <int> > divisors(sz, vector <int> ());

void get_divisors()
{
    int i, j;

    for (i = 1; i < sz; i++) {
        for (j = i; j < sz; j += i) {
            divisors[j].push_back(i);
        }
    }
}

void solve()
{
    int n, q, i;
    int l, r, k, ans;
    map <int, vector <int> > mp;

    cin >> n >> q;

    vector <int> v(n);

    for (auto &it : v) {
        cin >> it;
    }

    for (i = 0; i < n; i++) {
        mp[v[i]].push_back(i);
    }

    while (q--) {
        cin >> k >> l >> r;

        vector <pair <int, int> > temp;
        ans = 0;

        for (auto it : divisors[k]) {
            auto jt = mp.find(it);

            if (jt == mp.end()) {
                continue;
            }

            auto another_iterator = lower_bound(jt->second.begin(), jt->second.end(), l - 1);

            if (another_iterator == jt->second.end()) {
                continue;
            }

            if (*another_iterator < r) {
                temp.push_back({*another_iterator, it});
            }
        }

        sort(temp.begin(), temp.end());

        if (!temp.empty()) {
            ans += (temp[0].first - l + 1) * k;

            while ((k % temp[0].second) == 0) {
                k /= temp[0].second;
            }
        }

        for (i = 1; i < temp.size(); i++) {
            ans += (temp[i].first - temp[i - 1].first) * k;

            while ((k % temp[i].second) == 0) {
                k /= temp[i].second;
            }
        }

        if (temp.empty()) {
            ans += k * (r - l + 1);
        }
        else {
            ans += k * (r - temp.back().first);
        }

        cout << ans << "\n";
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    get_divisors();

    int32_t t, i;

    cin >> t;

    for (i = 1; i <= t; i++) {
        // cout << "Case " << i << ": ";

        solve();
    }

    return 0;
}