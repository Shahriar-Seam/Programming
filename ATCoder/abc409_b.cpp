#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <functional>
#include <bits/stdc++.h>

using namespace std;
using namespace __gnu_pbds;

typedef tree <pair <int, int>, null_type, less <pair <int, int> >, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, i, x, num = 0, cnt;
    ordered_set os;

    cin >> n;

    for (i = 0; i < n; i++) {
        cin >> x;

        os.insert({x, i});
    }

    for (i = 0; i <= n; i++) {
        cnt = os.order_of_key({i, -1});

        if (n - cnt >= i) {
            num = i;
        }
    }

    cout << num << "\n";

    return 0;
}