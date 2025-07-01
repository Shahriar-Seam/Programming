#include <bits/stdc++.h>

using namespace std;

#define int long long

const int inf = 1e9;

#define mn first
#define mx second

void solve()
{
    int n, i, k, extra = 0;
    map <int, int> mp;

    cin >> n;

    vector <int> v(n);
    vector <pair <int, int> > counter(n + 5, {inf, inf});
    vector <int> diff(n + 50, 0);

    for (auto &it : v) {
        cin >> it;

        mp[it]++;
    }

    sort(v.begin(), v.end());

    if (v[0] != 0) {
        for (i = 0; i <= n; i++) {
            cout << 1 << " ";
        }

        cout << "\n";

        return;
    }

    counter[0].mn = mp[0];
    counter[0].mx = n;

    extra = mp[0] - 1;

    for (i = 1; i < n; i++) {
        if (v[i] > v[i - 1] + 1) {
            counter[v[i - 1] + 1].mn = 0;
            counter[v[i - 1] + 1].mx = n - i + extra;

            break;
        }

        if (v[i] != v[i - 1]) {
            counter[v[i]].mn = mp[v[i]];
            counter[v[i]].mx = n - i + extra;

            extra += mp[v[i]] - 1;
        }
    }

    int f = 0;

    for (i = 0; i < n + 5; i++) {
        if (counter[i].mn == 0) {
            f = 1;

            break;
        }
    }

    if (!f) {
        for (i = 0; i < n + 5; i++) {
            if (counter[i].mn == inf) {
                counter[i].mn = 0;
                counter[i].mx = extra;

                break;
            }
        }
    }

    sort(counter.begin(), counter.end());

    for (i = 0; i < counter.size(); i++) {
        if (counter[i].mn == inf) {
            break;
        }

        diff[counter[i].mn]++;
        diff[counter[i].mx + 1]--;
    }

    for (i = 1; i < diff.size(); i++) {
        diff[i] += diff[i - 1];
    }

    for (k = 0; k <= n; k++) {
        cout << diff[k] << " ";
    }

    cout << "\n";
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