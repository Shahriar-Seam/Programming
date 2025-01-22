#include <bits/stdc++.h>

using namespace std;

#define int long long

void solve()
{
    int n, m, k, i, temp;

    cin >> n >> m;

    k = min(n, m);

    vector <int> A, B, v(1, 0);

    for (i = 0; i < n; i++) {
        cin >> temp;

        A.push_back(temp);
    }

    for (i = 0; i < m; i++) {
        cin >> temp;

        B.push_back(temp);
    }

    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    deque <int> a(A.begin(), A.end()), b(B.begin(), B.end());

    for (auto it : a) {
        cout << it << " ";
    }
    cout << "\n";

    for (auto it : b) {
        cout << it << " ";
    }
    cout << "\n";

    while (!a.empty() && !b.empty()) {
        if (a.size() > b.size()) {
            v.push_back(v.back() + )
        }
    }
}

int32_t main()
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