#include <bits/stdc++.h>

using namespace std;

#define int long long

bool possible(vector <int> &v, int n, int m)
{
    int i, j;
    int prev = v[0];

    for (i = 1, j = 1; i < v.size() && j < n; i++) {
        if (v[i] - prev >= m) {
            j++;

            prev = v[i];
        }
    }

    return j == n;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, i;
    int l, r, mid, min_distance = -1;

    cin >> n >> m;

    vector <int> v(m);

    for (auto &it : v) {
        cin >> it;
    }

    sort(v.begin(), v.end());

    for (l = 0, r = 1e12 + 5, i = 0; i < 65; i++) {
        mid = l + (r - l) / 2;

        if (possible(v, n, mid)) {
            min_distance = mid;

            l = mid + 1;
        }
        else {
            r = mid - 1;
        }
    }

    cout << min_distance << "\n";

    return 0;
}