#include <bits/stdc++.h>

using namespace std;

void solve()
{
    long long n, m, p, count = 0;

    cin >> n >> m >> p;

    if (n * m < p) {
        cout << -1 << "\n";
    }
    else if (n * m == p) {
        cout << p - 1 << "\n";
    }
    else if (n == 1 || m == 1) {
        cout << p << "\n";
    }
    else if (m > p && n > p) {
        cout << p + 1 << "\n";
    }
    else if ((p % n == 0) || (p % m == 0)) {
        cout << p << "\n";
    }
    else {
        while (p > 0) {
            if (abs(n - p) < abs(m - p)) {
                if (m > 1) {
                    count += 1;
                    m--;
                }
                count += min(p, n - 1);
                p -= min(p, n);
            }
            else {
                if (n > 1) {
                    count += 1;
                    n--;
                }
                count += min(p, m - 1);
                p -= min(p, m);
            }
        }
        cout << count << "\n";
    }
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