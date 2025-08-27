#include <bits/stdc++.h>

using namespace std;

bool possible(vector <int> &v, int m, int n, int k)
{
    int i, prev, count = 1;

    prev = v[0];

    for (i = 1; i < n; i++) {
        if (v[i] - prev >= m) {
            prev = v[i];

            count++;
        }
    }

    return count >= k;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    int l = 0, r = 1e9 + 5, m, dist;

    cin >> n >> k;

    vector <int> v(n);

    for (auto &it : v) {
        cin >> it;
    }

    sort(v.begin(), v.end());

    while (l <= r) {
        m = l + (r - l) / 2;

        if (possible(v, m, n, k)) {
            l = m + 1;

            dist = m;
        }
        else {
            r = m - 1;
        }
    }

    cout << dist << "\n";

    return 0;
}