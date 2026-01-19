#include <bits/stdc++.h>

using namespace std;

#define int long long

void solve()
{
    int n, m, h, b, c;
    deque <int> ops;

    cin >> n >> m >> h;

    vector <int> v(n), temp;

    for (auto &it : v) {
        cin >> it;
    }

    temp = v;

    while (m--) {
        cin >> b >> c;

        b--;

        v[b] += c;
        ops.push_back(b);

        if (v[b] > h) {
            while (!ops.empty()) {
                v[ops.front()] = temp[ops.front()];

                ops.pop_front();
            }
        }
    }

    for (auto &it : v) {
        cout << it << " ";
    }
    
    cout << "\n";
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