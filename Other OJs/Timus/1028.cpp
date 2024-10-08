#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/functional>
#include <bits/stdc++.h>

using namespace __gnu_pbds;
using namespace std;

typedef tree<pair <int, int>, null_type, less <pair <int, int> >, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, i, x, y;
    ordered_set o_set;

    cin >> n;

    vector <int> levels(n, 0);

    for (i = 0; i < n; i++) {
        cin >> x >> y;

        levels[o_set.order_of_key({x, i})]++;

        o_set.insert({x, i});
    }

    for (i = 0; i < n; i++) {
        cout << levels[i] << "\n";
    }

    return 0;
}