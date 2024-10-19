#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, ma, mi, a = 0, i;

    cin >> n;

    vector <int> v(n);

    for (auto &it : v) {
        cin >> it;
    }

    ma = *max_element(v.begin(), v.end());
    mi = *min_element(v.begin(), v.end());

    for (i = 1; i < n; i++) {
        a += ma - mi;
    }

    cout << a << "\n";
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