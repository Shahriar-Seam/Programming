#include <bits/stdc++.h>

using namespace std;

#define int long long

int contrast(vector <int> &v)
{
    int i, con = 0;

    for (i = 0; i < v.size() - 1; i++) {
        con += abs(v[i] - v[i + 1]);
    }

    return con;
}

void solve()
{
    int n, d, i;

    cin >> n;

    vector <int> v(n), temp;

    for (auto &it : v) {
        cin >> it;
    }

    if (contrast(v) == 0) {
        cout << 1 << "\n";

        return;
    }

    v.resize(distance(v.begin(), unique(v.begin(), v.end())));
    n = v.size();

    temp.push_back(v[0]);
    
    if (v[1] > v[0]) {
        d = 1;
    }
    else {
        d = -1;
    }

    for (i = 2; i < n; i++) {
        if (v[i] == v[i - 1]) {
            continue;
        }

        if (v[i] > v[i - 1] && d == -1) {
            temp.push_back(v[i - 1]);

            d = 1;
        }
        else if (v[i] < v[i - 1] && d == 1) {
            temp.push_back(v[i - 1]);

            d = -1;
        }
    }

    temp.push_back(v[n - 1]);

    cout << temp.size() << "\n";
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