#include <bits/stdc++.h>

using namespace std;

void print(vector <vector <int> > strips)
{
    for (auto it : strips) {
        for (auto itt : it) {
            cout << itt << " ";
        }

        cout << "\n";
    }
}

void solve()
{
    int n, m, i, j, k;
    int l, r, u, d;
    int count = 0;
    string s;

    cin >> n >> m;

    l = 0;
    r = m - 1;
    u = 0;
    d = n - 1;

    vector <vector <int> > v(n, vector <int> (m));
    vector <vector <int> > strips(min(n, m) / 2, vector <int> ());

    for (i = 0; i < n; i++) {
        cin >> s;

        for (j = 0; j < m; j++) {
            v[i][j] = s[j] - '0';
        }
    }

    for (k = 0; (r > l && d > u) && (k < min(n, m) / 2); k++) {
        for (i = l; i <= r; i++) {
            strips[k].push_back(v[u][i]);
        }

        u++;

        for (i = u; i <= d; i++) {
            strips[k].push_back(v[i][r]);
        }

        r--;

        for (i = r; i >= l; i--) {
            strips[k].push_back(v[d][i]);
        }

        d--;

        for (i = d; i >= u; i--) {
            strips[k].push_back(v[i][l]);
        }

        l++;

        strips[k].push_back(strips[k][0]);
        strips[k].push_back(strips[k][1]);
        strips[k].push_back(strips[k][2]);
    }

    for (auto it : strips) {
        for (i = 0; i < it.size() - 3; i++) {
            if (it[i] == 1 && it[i + 1] == 5 && it[i + 2] == 4 && it[i + 3] == 3) {
                count++;
            }
        }
    }

    cout << count << "\n";
}

int main()
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);

    int t;

    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}