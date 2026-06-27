#include <bits/stdc++.h>

using namespace std;

#define int long long

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cout << fixed << setprecision(8);

    int n, w;
    double val = 0;

    cin >> n >> w;

    vector <pair <int, int> > v(n);

    for (auto &it : v) {
        cin >> it.first >> it.second;
    }

    sort(v.begin(), v.end(), [&] (pair <int, int> &a, pair <int, int> &b) {
        return a.first * b.second > a.second * b.first;
    });

    for (auto &it : v) {
        if (it.second < w) {
            w -= it.second;
            val += it.first;
        }
        else {
            val += 1.0 * it.first * w / it.second;
            w = 0;
            break;
        }
    }

    cout << val << "\n";

    return 0;
}