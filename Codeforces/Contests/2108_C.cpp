#include <bits/stdc++.h>

using namespace std;

bool valid(int index, int n)
{
    return index >= 0 && index < n;
}

void solve()
{
    int n, i, clones = 0;
    map <int, vector <int>, greater <int> > indices;

    cin >> n;

    vector <int> v(n), visited(n, 0);

    for (i = 0; i < n; i++) {
        cin >> v[i];

        indices[v[i]].push_back(i);
    }

    for (auto it : indices) {
        for (auto jt : it.second) {
            if (!visited[jt]) {
                visited[jt] = 1;

                clones++;

                // left
                if (valid(jt - 1, n) && v[jt - 1] <= it.first) {
                    i = jt - 1;

                    while (i >= 0 && v[i] <= v[i + 1]) {
                        visited[i] = 1;

                        i--;
                    }
                }

                // right
                if (valid(jt + 1, n) && v[jt + 1] <= it.first) {
                    i = jt + 1;

                    while (i < n && v[i] <= v[i - 1]) {
                        visited[i] = 1;

                        i++;
                    }
                }
            }
        }
    }

    cout << clones << "\n";
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