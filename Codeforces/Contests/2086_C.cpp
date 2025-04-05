#include <bits/stdc++.h>

using namespace std;

#define int long long

void recurse(vector <int> &p, vector <int> &d, vector <int> &visited, int node, int &cnt)
{
    if (!visited[node]) {
        visited[node] = 1;
        cnt++;

        recurse(p, d, visited, p[node - 1], cnt);
    }
}

void solve()
{
    int n, i, count = 0;

    cin >> n;

    vector <int> p(n), d(n), visited(n + 1, 0);

    for (auto &it : p) {
        cin >> it;
    }

    for (auto &it : d) {
        cin >> it;
    }

    for (i = 0; i < n; i++) {
        if (!visited[d[i]]) {
            int cnt = 0;

            recurse(p, d, visited, d[i], cnt);

            count += cnt;
        }

        cout << count << " ";
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