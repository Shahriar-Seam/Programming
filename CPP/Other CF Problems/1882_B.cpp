#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int t, i, j, n, temp, elements = 0;
    vector <set <int> > v;
    set <int> s, universal_set, big_set;

    cin >> t;

    for (i = 0; i < t; i++) {
        cin >> n;

        s.clear();

        for (j = 0; j < n; j++) {
            cin >> temp;

            s.insert(temp);
        }

        v.push_back(s);
        universal_set.insert(begin(s), end(s));
    }

    for (auto it_i : universal_set) {
        big_set.clear();

        for (auto it_j : v) {
            if (it_j.find(it_i) == end(it_j)) {
                big_set.insert(begin(it_j), end(it_j));
            }
        }

        elements = max(elements, (int) big_set.size());
    }

    cout << elements << "\n";
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