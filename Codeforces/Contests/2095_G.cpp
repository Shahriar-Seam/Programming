#include <bits/stdc++.h>

using namespace std;

#define int long long

double square(double n)
{
    return n * n;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cout << fixed << setprecision(15);

    int n, k, i, x, y;
    double area = 15e18;
    double pi = acos(-1);

    cin >> n >> k;

    vector <pair <int, int> > v;

    for (i = 0; i < n; i++) {
        cin >> x >> y;
        v.push_back({x, y});
    }

    sort(v.begin(), v.end());

    area = pi * (square(v[0].first - v[k - 1].first) + square(v[0].second - v[k - 1].second)) / 4;

    for (i = k; i < v.size(); i++) {
        area = min(area, pi * (square(v[i].first - v[i - k + 1].first) + square(v[i].second - v[i - k + 1].second)) / 4);
    }

    cout << area << "\n";

    return 0;
}