#include <bits/stdc++.h>

using namespace std;

int max_sum(pair <int, int> &a, pair <int, int> &b)
{
    vector <int> v = {a.first, a.second, b.first, b.second};

    sort(v.begin(), v.end());
    
    return v[3] - v[0] + v[2] - v[1];
}

void solve()
{
    int n, k, i, j;
    long long min_add = 2e9 + 50;
    long long total = 0;

    cin >> n >> k;

    vector <pair <int, int> > v(n);
    vector <int> diff;

    for (auto &it : v) {
        cin >> it.first;
    }
    
    for (auto &it : v) {
        cin >> it.second;
    }

    sort(v.begin(), v.end());

    for (auto &it : v) {
        diff.push_back(abs(it.first - it.second));
    }

    for (i = 0; i < n; i++) {
        int temp = min(n, i + 100);
        for (j = i + 1; j < temp; j++) {
            int sum = max_sum(v[i], v[j]);
            int sub = diff[i] + diff[j];

            if (sum - sub < min_add) {
                min_add = sum - sub;
            }
        }
    }

    for (i = 0; i < n; i++) {
        total += 1LL * diff[i];
    }

    cout << total + min_add << "\n";
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