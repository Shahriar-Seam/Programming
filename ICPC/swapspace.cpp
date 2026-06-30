#include <bits/stdc++.h>

using namespace std;

#define int long long

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, c = 0, cost = 0, i;
    pair <int, int> p;

    cin >> n;

    vector <pair <int, int> > v, pos, neg;

    while (n--) {
        cin >> p.first >> p.second;

        if (p.first <= p.second) {
            pos.push_back(p);
        }
        else {
            neg.push_back(p);
        }
    }

    sort(pos.begin(), pos.end(), [&] (pair <int, int> &a, pair <int, int> &b) {
        if (a.first == b.first) {
            return a.second > b.second;
        }
        else {
            return a.first < b.first;
        }
    });

    sort(neg.begin(), neg.end(), [&] (pair <int, int> &a, pair <int, int> &b) {
        if (a.second == b.second) {
            return a.first > b.first;
        }
        else {
            return a.second > b.second;
        }
    });

    for (auto &it : pos) {
        v.push_back(it);
    }

    for (auto &it : neg) {
        v.push_back(it);
    }

    for (auto &it : v) {
        if (it.first > c) {
            cost += it.first - c;

            c = it.second;
        }
        else {
            c = c - it.first + it.second;
        }
    }

    cout << cost << "\n";

    return 0;
}