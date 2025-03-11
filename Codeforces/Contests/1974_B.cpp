#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n;

    cin >> n;

    vector <int> v(n);
    multiset <int> ms;

    for (auto &it : v) {
        cin >> it;
    }

    for (auto it : v) {
        ms.insert(it);
    }

    while (ms.size() > 1) {
        int a = *ms.begin();
        ms.erase(ms.begin());

        int b = *ms.begin();
        ms.erase(ms.begin());

        ms.insert(a + b - 1);
    }

    cout << *ms.begin() << "\n";
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