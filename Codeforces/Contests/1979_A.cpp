#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, i, temp, k = INT_MAX;
    vector <int> v;

    cin >> n;

    for (i = 0; i < n; i++) {
        cin >> temp;

        v.push_back(temp);
    }

    for (i = 1; i < n; i++) {
        k = min(k, max(v[i], v[i - 1]));
    }

    cout << k - 1 << "\n";
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