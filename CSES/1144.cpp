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

    int n, q, i;
    ordered_set os;
    char type;
    int k, x, a, b;

    cin >> n >> q;

    vector <int> v(n);

    for (i = 0; i < n; i++) {
        cin >> v[i];

        os.insert({v[i], i});
    }
    
    while (q--) {
        cin >> type;

        if (type == '!') {
            cin >> k >> x;

            k--;

            os.erase({v[k], k});

            v[k] = x;

            os.insert({v[k], k});
        }
        else {
            cin >> a >> b;

            cout << os.order_of_key({b, INT_MAX}) - os.order_of_key({a, -1}) << "\n";
        }
    }

    return 0;
}