#include <bits/stdc++.h>

using namespace std;

#define int long long

void solve()
{
    int n, a, b, emeralds = 0;
    priority_queue <int> pq;

    cin >> n;

    vector <int> v(n);

    for (auto &it : v) {
        cin >> it;

        pq.push(it);
    }

    while (pq.size() > 1) {
        int a, b;

        a = pq.top();
        pq.pop();
        b = pq.top();
        pq.pop();

        emeralds += a;
    }

    if (n & 1) {
        emeralds += pq.top();
    }

    cout << emeralds << "\n";
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