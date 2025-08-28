#include <bits/stdc++.h>

using namespace std;

#define int long long

void solve()
{
    int n, i, j, end = 0, count = 0;

    cin >> n;

    vector <int> v(n), memo(n + 1, 0);
    vector <vector <int> > indices(n + 1, vector <int> ());

    for (i = 0; i < n; i++) {
        cin >> v[i];

        indices[v[i]].push_back(i);
    }

    for (i = 0; i < n; i++) {
        int index = lower_bound(indices[v[i]].begin(), indices[v[i]].end(), i) - indices[v[i]].begin();

        if (i > 0) {
            memo[i + 1] = memo[i];
        }

        if (index >= v[i] - 1) {
            memo[i + 1] = max(memo[i + 1], memo[indices[v[i]][index - v[i] + 1]] + v[i]);
        }
    }
    
    cout << memo[n] << "\n";
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