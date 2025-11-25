#include <bits/stdc++.h>

using namespace std;

struct item {
    int s, i, j;

    item(int s, int i, int j) : s(s), i(i), j(j) {}

    bool operator < (item it) const {
        return s < it.s;
    }

    bool operator == (item it) const {
        return s == it.s;
    }
};

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, x, i, j;
    set <item> s;

    cin >> n >> x;

    vector <int> v(n);

    for (auto &it : v) {
        cin >> it;
    }

    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            s.insert({v[i] + v[j], i, j});
        }
    }

    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            auto it = s.find({x - v[i] - v[j], -1, -1});

            if (it != s.end()) {
                if (i == it->i || i == it->j || j == it->i || j == it->j) {
                    // do nothing
                }
                else {
                    cout << i + 1 << " " << j + 1 << " " << it->i + 1 << " " << it->j + 1 << "\n";

                    exit(0);
                }
            }
        }
    }

    cout << "IMPOSSIBLE" << "\n";

    return 0;
}