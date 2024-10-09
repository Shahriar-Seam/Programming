#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <functional>
#include <bits/stdc++.h>

using namespace std;
using namespace __gnu_pbds;

typedef tree <pair <int, int>, null_type, less <pair <int, int> >, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;

void solve()
{
    int n, d, i, max_diff = 0;
    ordered_multiset ms;

    cin >> n >> d;

    vector <int> v(n);

    for (auto &it : v) {
        cin >> it;
    }

    for (i = 0; i < d; i++) {
        ms.insert({v[i], i});
    }

    for (i = d; i < n; i++) {
        max_diff = max(max_diff, (*ms.rbegin()).first - (*ms.find_by_order(0)).first);

        ms.insert({v[i], i});
        ms.erase({v[i - d], i - d});
    }

    max_diff = max(max_diff, (*ms.rbegin()).first - (*ms.find_by_order(0)).first);

    cout << max_diff << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t, i;

    cin >> t;

    for (i = 1; i <= t; i++) {
        cout << "Case " << i << ": ";
        solve();
    }

    return 0;
}