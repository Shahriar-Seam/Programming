#include <bits/stdc++.h>

using namespace std;

int max_index(vector <int> &v)
{
    int i, m_index = -1, m = 0;

    for (i = 1; i <= 20; i++) {
        if (v[i] > m) {
            m = v[i];

            m_index = i;
        }
    }

    return m_index;
}

void solve()
{
    int n, k, i, ops = 2;

    cin >> n >> k;

    vector <int> v(n), vv(21, 0);

    for (auto &it : v) {
        cin >> it;
    }

    for (i = 0; i < n; i++) {
        vv[v[i]]++;
    }

    if (vv[max_index(vv)] == vv[k]) {
        cout << 0 << "\n";

        return;
    }

    for (i = 0; i < n; i++) {
        if (vv[max_index(vv)] == vv[k]) {
            ops = 1;

            break;
        }

        vv[v[i]]--;
    }

    vv.assign(21, 0);

    for (i = 0; i < n; i++) {
        vv[v[i]]++;
    }

    for (i = n - 1; i >= 0; i--) {
        if (vv[max_index(vv)] == vv[k]) {
            ops = 1;

            break;
        }

        vv[v[i]]--;
    }

    cout << ops << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;

    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}