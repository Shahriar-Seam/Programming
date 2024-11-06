#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, i;

    cin >> n;

    vector <int> v(2 * n);
    vector <pair <int, int> > p;

    for (auto &it : v) {
        cin >> it;
    }

    for (i = 0; i < 10 && !is_sorted(v.begin(), v.end()); i++) {
        if (i % 3 == 0) {
            sort(v.begin(), v.begin() + n);
            
            p.push_back({1, n});
        }
        else if (i % 3 == 1) {
            sort(v.begin() + n / 2, v.begin() + n + n / 2);

            p.push_back({n / 2 + 1, n + n / 2});
        }
        else {
            sort(v.begin() + n, v.begin() + 2 * n);

            p.push_back({n + 1, 2 * n});
        }
    }

    cout << p.size() << "\n";

    for (auto it : p) {
        cout << it.first << " " << it.second << "\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t, i;

    cin >> t;

    for (i = 1; i <= t; i++) {
        cout << "Case " << i << ": ";
        solve();
    }

    return 0;
}