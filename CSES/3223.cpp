#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <functional>
#include <bits/stdc++.h>

using namespace std;
using namespace __gnu_pbds;

#define int long long

typedef tree <pair <int, int>, null_type, less <pair <int, int> >, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k, i, count = 0, inf = 1e9;
    ordered_set os;

    cin >> n >> k;

    vector <int> v(n);

    for (auto &it : v) {
        cin >> it;
    }

    for (i = 0; i < k; i++) {
        count += os.size() - os.order_of_key({v[i], inf});

        os.insert({v[i], i});
    }

    cout << count << " ";

    for (i = k; i < n; i++) {
        count -= os.order_of_key({v[i - k], -1});
        os.erase({v[i - k], i - k});

        count += os.size() - os.order_of_key({v[i], inf});
        os.insert({v[i], i});

        cout << count << " ";
    }

    cout << "\n";

    return 0;
}