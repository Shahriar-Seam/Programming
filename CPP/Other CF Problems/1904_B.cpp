#include <bits/stdc++.h>

using namespace std;

#define int long long

void solve()
{
    int n, i, j, k, count = 0, sum = 0;

    cin >> n;

    vector <pair <int, int> > v(n);
    vector <int> can_remove(n);

    for (i = 0; i < n; i++) {
        cin >> v[i].first;

        v[i].second = i;
    }

    sort(v.begin(), v.end());

    for (i = 0, j = 0; i < n; ) {
        sum += v[i].first;

        j = i + 1;

        while (j < n && v[j].first <= sum) {
            count++;
            sum += v[j].first;
            j++;
        }

        for (k = i; k < j; k++) {
            can_remove[v[k].second] = count;
        }

        i = j;

        count = max(count, i);
    }

    for (auto it : can_remove) {
        cout << it << " ";
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