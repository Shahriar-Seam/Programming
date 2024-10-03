#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/functional>
#include <bits/stdc++.h>

using namespace __gnu_pbds;
using namespace std;

typedef tree<int, null_type, less <int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k, last = 0, i;
    ordered_set s;

    cin >> n >> k;

    for (i = 1; i <= n; i++) {
        s.insert(i);
    }

    for (i = 0; i < n; i++) {
        last = (last + k - 1) % s.size();

        auto it = s.find_by_order(last);

        cout << *it << "\n";

        s.erase(it);
    }

    return 0;
}