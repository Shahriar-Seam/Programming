#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, i, prev, current;

    cin >> n;

    vector <int> a(n), b(n);

    for (auto &it : a) {
        cin >> it;
    }

    for (auto &it : b) {
        cin >> it;
    }

    prev = a[0];
    current = a[0] + b[0];

    for (i = 1; i < n; i++) {
        
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