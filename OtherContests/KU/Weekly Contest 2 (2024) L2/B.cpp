#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <functional>
#include <bits/stdc++.h>

using namespace std;
using namespace __gnu_pbds;

typedef tree <pair <int, int>, null_type, less <pair <int, int> >, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k, i;
    ordered_multiset oms;

    cin >> n >> k;

    vector <int> v(n);

    for (auto &it : v) {
        cin >> it;
    }

    for (i = 0; i < k; i++) {
        oms.insert({v[i], i});
    }

    cout << oms.find_by_order((k - 1) / 2)->first << " ";

    for (i = k; i < n; i++) {
        oms.erase(oms.find({v[i - k], i - k}));
        oms.insert({v[i], i});

        cout << oms.find_by_order((k - 1) / 2)->first << " ";
    }

    return 0;
}