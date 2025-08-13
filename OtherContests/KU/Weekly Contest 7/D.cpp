#include <bits/stdc++.h>

using namespace std;

int max_sub_sum(vector <vector <int> > &v, vector <vector <int> > &pref, int k)
{
    k--;
    int n = pref.size();
    int m = pref[0].size();

    int sum = pref[min(k, n - 1)][min(k, n - 1)];

    for (i = 0; i < n - k; i++) {
        for (j = 0; j < m - k; j++) {
            sum = max(sum, pref[i + k][j + k] - pref[i][j])
        }
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, i, j;

    cin >> n >> m;

    vector <vector <int> > v(n, vector <int> (m)), pref(n, vector <int> (m, 0));

    for (auto &it : v) {
        for (auto &jt : it) {
            cin >> jt;
        }
    }

    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            pref[i][j] = v[i][j] + (j > 0 ? pref[i][j - 1] : 0) + (i > 0 ? pref[i - 1][j] : 0) - (i > 0 && j > 0 ? pref[i - 1][j - 1] : 0);
        }
    }

    for (auto &it : pref) {
        for (auto &jt : it) {
            cout << jt << " ";
        }

        cout << "\n";
    }

    return 0;
}