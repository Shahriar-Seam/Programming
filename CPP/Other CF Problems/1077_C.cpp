#include <bits/stdc++.h>

using namespace std;

#define int long long

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, sum = 0, i;

    cin >> n;

    vector <pair <int, int> > v(n);
    vector <int> pos;

    for (i = 0; i < n; i++) {
        cin >> v[i].first;

        v[i].second = i + 1;

        sum += v[i].first;
    }

    sort(v.begin(), v.end(), greater <> ());

    sum -= v[0].first;

    for (i = 1; i < n; i++) {
        if (sum - v[i].first == v[0].first) {
            pos.push_back(v[i].second);
        }
    }

    if (n > 2) {
        if (sum - v[1].first == v[1].first) {
            pos.push_back(v[0].second);
        }
    }

    cout << pos.size() << "\n";

    for (auto &it : pos) {
        cout << it << " ";
    }

    cout << "\n";

    return 0;
}