#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <functional>

using namespace std;
using namespace __gnu_pbds;

typedef tree <pair <int, int>, null_type, less <pair <int, int> >, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, temp, i;
    ordered_multiset oms;

    cin >> n >> m;

    for (i = 0; i < n; i++) {
        cin >> temp;

        oms.insert({temp, i});
    }

    i = INT_MAX;

    while (m--) {
        cin >> temp;

        cout << oms.order_of_key({temp, i}) << " ";
    }

    return 0;
}