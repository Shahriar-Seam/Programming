#include <bits/stdc++.h>

using namespace std;

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, i;
    pair <string, int> vasya;

    cin >> n;

    vector <pair <string, int> > v(n);

    for (auto &it : v) {
        cin >> it.first >> it.second;
    }

    cin >> m;

    vector <int> b(m);

    for (auto &it : m) {
        cin >> it;
    }

    cin >> vasya.first;

    for (i = 0; i < n; i++) {
        if (v[i].first == vasya.first) {
            vasya.second = v[i].second;

            v.erase(v.begin() + i);

            break;
        }
    }

    sort()

    return 0;
}