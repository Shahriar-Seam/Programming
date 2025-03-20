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

    int x, n, p, l, r;
    ordered_set s;
    set <pair <int, pair <int, int> >, greater <pair <int, pair <int, int> > > > pq;

    cin >> x >> n;

    s.insert(0);
    s.insert(x);

    pq.insert({x, {0, x}});

    while (n--) {
        cin >> p;

        auto i = s.order_of_key(p);

        l = *s.find_by_order(i - 1);
        r = *s.find_by_order(i);

        s.insert(p);

        pq.erase({r - l, {l, r}});

        pq.insert({p - l, {l, p}});
        pq.insert({r - p, {p, r}});

        cout << (*pq.begin()).first << " ";
    }

    return 0;
}