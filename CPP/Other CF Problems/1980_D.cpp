#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, i, j, g;

    cin >> n;

    vector <int> a(n), b;

    for (auto &it : a) {
        cin >> it;
    }

    for (i = 1; i < n; i++) {
        b.push_back(gcd(a[i], a[i - 1]));
    }

    if (is_sorted(b.begin(), b.end()) || is_sorted(b.begin() + 1, b.end()) || is_sorted(b.begin(), b.begin() + n - 2)) {
        cout << "YES\n";

        return;
    }

    b.clear();

    b.push_back(gcd(a[0], a[1]));

    for (i = 1; i < n - 2; i++) {
        g = gcd(a[i], a[i + 1]);

        if (g < b.back()) {
            vector <int> b1, b2, b3;

            b1 = b2 = b3 = b;

            b1.pop_back();
            b2.pop_back();

            // a[i - 1] removed
            if (b1.size() > 0) {
                b1.pop_back();
            }
            b1.push_back(gcd(a[i], a[i - 2]));

            for (j = i; j < n - 1; j++) {
                b1.push_back(gcd(a[j], a[j + 1]));
            }

            // a[i] removed
            b2.push_back(gcd(a[i - 1], a[i + 1]));

            for (j = i + 1; j < n - 1; j++) {
                b2.push_back(gcd(a[j], a[j + 1]));
            }

            // a[i + 1] removed
            b3.push_back(gcd(a[i], a[i + 2]));

            for (j = i + 2; j < n - 1; j++) {
                b3.push_back(gcd(a[j], a[j + 1]));
            }

            if (is_sorted(b1.begin(), b1.end()) || is_sorted(b2.begin(), b2.end()) || is_sorted(b3.begin(), b3.end())) {
                cout << "YES\n";

                return;
            }
            else {
                break;
            }
        }
        else {
            b.push_back(g);
        }
    }

    cout << "NO\n";
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int32_t t, i;

    cin >> t;

    for (i = 1; i <= t; i++) {
        // cout << "Case " << i << ": ";

        solve();
    }

    return 0;
}