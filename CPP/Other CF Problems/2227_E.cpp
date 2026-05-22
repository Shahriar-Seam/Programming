#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <functional>
#include <bits/stdc++.h>

using namespace std;
using namespace __gnu_pbds;

#define int long long

typedef tree <pair <int, int>, null_type, less <pair <int, int> >, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

void solve()
{
    int n, i, sum = 0, mn = 1e9, mx = 0;
    ordered_set os;

    cin >> n;

    vector <int> v(n);

    for (i = 0; i < n; i++) {
        cin >> v[i];
    }

    for (i = n - 1; i >= 0; i--) {
        sum += max(0LL, v[i] - mn);

        mn = min(mn, v[i]);

        os.insert({mn, i});
    }

    mn = 1e9;

    for (i = n - 1; i >= 0; i--) {
        mn = min(mn, v[i]);

        os.erase({mn, i});

        mx = max(mx, (int) (os.size() - os.order_of_key({mn, -1})));
    }

    cout << sum + mx << "\n";
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