#include <bits/stdc++.h>

using namespace std;

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, a, b, i, count = 0, max_count = 0;

    cin >> n;

    vector <pair <int, int> > v;

    for (i = 0; i < n; i++) {
        cin >> a >> b;

        v.push_back({a, 1});
        v.push_back({b, -1});
    }

    sort(v.begin(), v.end());

    for (auto &it : v) {
        count += it.second;

        max_count = max(max_count, count);
    }

    cout << max_count << "\n";

    return 0;
}