#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, x, y = 0;

    cin >> n >> x;

    deque <int> a(n), b(n), c(n);

    for (auto &it : a) {
        cin >> it;
    }

    for (auto &it : b) {
        cin >> it;
    }

    for (auto &it : c) {
        cin >> it;
    }

    while (true) {
        if (!a.empty() && (a.front() | x) == x) {
            y |= a.front();

            a.pop_front();
        }
        else if (!b.empty() && (b.front() | x) == x) {
            y |= b.front();

            b.pop_front();
        }
        else if (!c.empty() && (c.front() | x) == x) {
            y |= c.front();

            c.pop_front();
        }
        else {
            break;
        }
    }

    cout << (x == y ? "YES" : "NO") << "\n";
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