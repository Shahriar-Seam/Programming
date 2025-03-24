#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <functional>
#include <bits/stdc++.h>

using namespace std;
using namespace __gnu_pbds;

typedef tree <int, null_type, less <int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, i, k, c;
    ordered_set os;

    cin >> n >> k;

    for (i = 1; i <= n; i++) {
        os.insert(i);
    }

    i = k;

    while (!os.empty()) {
        i = i % os.size();

        c = *os.find_by_order(i);

        os.erase(c);

        cout << c << " ";

        i += k;
    }

    return 0;
}