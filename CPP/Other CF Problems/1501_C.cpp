#include <bits/stdc++.h>

using namespace std;

const int sz = 5e6;

bool valid(int a, int b, int c, int d)
{
    if (a == c || a == d || b == c || b == d) {
        return false;
    }
    else {
        return true;
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, i, j;
    int x = -1, y, z, w;

    cin >> n;

    vector <pair <int, int> > v(n), diff(sz);

    for (i = 0; i < sz; i++) {
        diff[i] = {-1, -1};
    }

    for (i = 0; i < n; i++) {
        cin >> v[i].first;

        v[i].second = i + 1;
    }

    sort(v.begin(), v.end());

    for (i = 0; i < min(n, 1500); i++) {
        for (j = i + 1; j < min(n, 1500); j++) {
            if (diff[v[j].first - v[i].first] == make_pair(-1, -1)) {
                diff[v[j].first - v[i].first] = {v[j].second, v[i].second};
            }
            else if (valid(diff[v[j].first - v[i].first].first, diff[v[j].first - v[i].first].second, v[j].second, v[i].second)) {
                x = diff[v[j].first - v[i].first].first;
                w = diff[v[j].first - v[i].first].second;

                z = v[j].second;
                y = v[i].second;

                break;
            }
        }
    }

    if (x == -1) {
        cout << "NO\n";
    }
    else {
        cout << "YES\n";

        cout << x << " " << y << " " << z << " " << w << "\n";
    }

    return 0;
}