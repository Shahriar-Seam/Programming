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

    int n, i;
    ordered_set x, y;

    cin >> n;

    vector <pair <int, int> > v(n);
    vector <int> levels(n, 0);

    for (i = 0; i < n; i++) {
        cin >> v[i].first >> v[i].second;

        x.insert(v[i].first);
        y.insert(v[i].second);
    }

    for (i = 0; i < n; i++) {
        levels[max(x.order_of_key(v[i].first), y.order_of_key(v[i].second)) + 1]++;

        cout << max(x.order_of_key(v[i].first), y.order_of_key(v[i].second)) + 1 << " ";
    }

    cout << "\n";

    for (auto it : x) {
        cout << it << " ";
    }

    cout << "\n";

    for (auto it : y) {
        cout << it << " ";
    }

    cout << "\n";

    for (i = 0; i < n; i++) {
        cout << levels[i] << "\n";
    }

    return 0;
}