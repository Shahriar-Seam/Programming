#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    multiset <int> h;
    int t, p;

    int n, m;

    cin >> n >> m;

    while (n--) {
        cin >> t;

        h.insert(t);
    }

    while (m--) {
        cin >> t;

        auto it = h.upper_bound(t);

        if (it != begin(h)) {
            it--;

            p = *it;

            if (p <= t) {
                h.erase(it);

                cout << p << "\n";
            }
            else {
                cout << -1 << "\n";
            }
        }
        else {
            cout << -1 << "\n";
        }
    }

    return 0;
}