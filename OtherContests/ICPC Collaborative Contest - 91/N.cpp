#include <bits/stdc++.h>

using namespace std;

#define int long long

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, a = 0, b = 0, i;

    cin >> n;

    vector <pair <int, int> > v(n * 2);

    for (auto &it : v) {
        cin >> it.first >> it.second;

        if (it.first > it.second) {
            swap(it.first, it.second);
        }
    }

    sort(v.begin(), v.end(), [&] (pair <int, int> &a, pair <int, int> &b) {
        return a.first + a.second < b.first + b.second;
    });

    for (i = 0; i < n; i++) {
        a += v[i].first;

        b += v[i + n].second;
    }

    cout << b - a << "\n";

    return 0;
}