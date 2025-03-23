#include <bits/stdc++.h>

using namespace std;

#define int long long

int square(int n)
{
    return n * n;
}

int max(int a, int b)
{
    return a > b ? a : b;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, i, j, d = LONG_LONG_MAX;

    cin >> n;

    vector <pair <int, pair <int, int> > > v(n);
    
    for (i = 0; i < n; i++) {
        cin >> v[i].second.first >> v[i].second.second;

        v[i].first = v[i].second.first * v[i].second.first + v[i].second.second * v[i].second.second;
    }

    sort(v.begin(), v.end());

    for (i = 0; i < n; i++) {
        for (j = max(0, i - 50); j < min(n, i + 50); j++) {
            if (j != i) {
                d = min(d, square(v[i].second.first - v[j].second.first) + square(v[j].second.second - v[i].second.second));
            }
        }
    }

    cout << d << "\n";

    return 0;
}