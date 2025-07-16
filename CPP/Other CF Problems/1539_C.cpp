#include <bits/stdc++.h>

using namespace std;

#define int long long

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k, x, i, count = 0;

    cin >> n >> k >> x;

    vector <int> v(n), dist;

    for (auto &it : v) {
        cin >> it;
    }

    sort(v.begin(), v.end());

    for (i = 1; i < n; i++) {
        if (v[i] - v[i - 1] > x) {
            dist.push_back((v[i] - v[i - 1] - 1) / x);
        }
    }

    sort(dist.begin(), dist.end());

    count = dist.size() + 1;

    for (i = 0; i < dist.size(); i++) {
        if (dist[i] <= k) {
            k -= dist[i];

            count--;
        }
    }

    cout << count << "\n";

    return 0;
}