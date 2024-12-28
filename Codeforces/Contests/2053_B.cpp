#include <bits/stdc++.h>

using namespace std;

struct item {
    pair <int, int> p;
    int count;
};

item make_item(pair <int, int> p, int count)
{
    item it;
    it.p = p;
    it.count = count;

    return it;
}

int bound(vector <item> &v, pair <int, int> p)
{
    int l = 0, r = v.size() - 1, m, index = r + 1;

    while (l <= r) {
        m = (l + r) / 2;

        if (v[m].p >= p) {
            index = m;

            r = m - 1;
        }
        else {
            l = m + 1;
        }
    }

    return index;
}

void solve()
{
    int n, i, l, r;
    int left_index, right_index, len;
    map <pair <int, int>, int> mp;
    vector <item> counter;

    cin >> n;

    vector <pair <int, int> > v(n);

    for (i = 0; i < n; i++) {
        cin >> v[i].first >> v[i].second;
    }

    for (i = 0; i < n; i++) {
        if (v[i].first == v[i].second) {
            mp[v[i]]++;
        }
    }

    for (auto it : mp) {
        counter.push_back(make_item(it.first, it.second));
    }

    for (auto it : v) {
        l = it.first;
        r = it.second;

        if (l == r) {
            if (mp[it] > 1) {
                cout << 0;
            }
            else {
                cout << 1;
            }

            continue;
        }

        left_index = bound(counter, {l, l});
        right_index = bound(counter, {r, r});

        if (right_index == counter.size() || counter[right_index].p.second > r) {
            right_index--;
        }

        len = right_index - left_index + 1;

        if (len < it.second - it.first + 1) {
            cout << 1;
        }
        else {
            cout << 0;
        }
    }

    cout << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;

    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}