#include <bits/stdc++.h>

using namespace std;

#define int long long

void solve()
{
    int n, m, i, j = 0, happy = 0;

    cin >> n >> m;

    vector <pair <int, int> > v(n), h;

    for (auto &it : v) {
        cin >> it.first >> it.second;
    }

    sort(v.begin(), v.end(), [&] (pair <int, int> a, pair <int, int> b) {
        if (a.second == b.second) {
            return a.first < b.first;
        }
        else {
            return a.second > b.second;
        }
    });

    for (auto &it : v) {
        if (it.first <= it.second) {
            if (h.size() < m) {
                h.push_back(it);

                j++;
            }

            if (h.size() < m) {
                h.push_back(pair(0LL, 0LL));
            }
        }
        else {
            if (h.size() < m) {
                h.push_back(it);

                j++;
            }
        }
    }

    for (i = h.size() - 1, j; i >= 0 && j < n; i--) {
        if (h[i] == pair(0LL, 0LL)) {
            h[i] = v[j++];
        }
    }

    for (i = 0; i < h.size(); i++) {
        if (i == 0) {
            if (h[1] == pair(0LL, 0LL)) {
                happy += h[0].second;
            }
            else {
                happy += h[0].first;
            }
        }
        else if (i == h.size() - 1) {
            if (h[i - 1] == pair(0LL, 0LL)) {
                happy += h[i].second;
            }
            else {
                happy += h[i].first;
            }
        }
        else {
            if (h[i - 1] == pair(0LL, 0LL) && h[i + 1] == pair(0LL, 0LL)) {
                happy += h[i].second;
            }
            else {
                happy += h[i].first;
            }
        }
    }

    cout << happy << "\n";
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int32_t t, i;

    cin >> t;

    for (i = 1; i <= t; i++) {
        // cout << "Case " << i << ": ";

        solve();
    }

    return 0;
}