#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, c, i;
    int min_index, min_price;
    map <int, set <int> > mp;
    map <int, vector <int> > indices;

    indices[1] = {2, 5, 10};
    indices[2] = {5, 8, 13};
    indices[3] = {10, 13, 18};

    cin >> n;

    vector <int> p(n), a(n), b(n);

    for (auto &it : p) {
        cin >> it;
    }

    for (auto &it : a) {
        cin >> it;
    }

    for (auto &it : b) {
        cin >> it;
    }

    for (i = 0; i < n; i++) {
        mp[a[i] * a[i] + b[i] * b[i]].insert(p[i]);
    }

    cin >> m;

    while (m--) {
        cin >> c;

        min_price = INT_MAX;

        for (auto i : indices[c]) {
            if (mp.find(i) != mp.end()) {
                if (min_price > *mp[i].begin()) {
                    min_price = *mp[i].begin();

                    min_index = i;
                }
            }
        }

        if (min_price == INT_MAX) {
            cout << -1 << " ";
        }
        else {
            cout << min_price << " ";

            if (mp[min_index].size() == 1) {
                mp.erase(min_index);
            }
            else {
                mp[min_index].erase(mp[min_index].begin());
            }
        }
    }

    return 0;
}