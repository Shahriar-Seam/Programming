#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/functional>
#include <bits/stdc++.h>

using namespace __gnu_pbds;
using namespace std;

typedef tree<pair <int, int>, null_type, less <pair <int, int> >, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

int get_mex(ordered_set &s)
{
    int mex = 0;

    while (true) {
        if ((*s.find_by_order(s.order_of_key({mex, int(1e9)}) - 1)).first == mex) {
            mex++;
        }
        else {
            break;
        }
    }

    return mex;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n, k, i, min_mex = int(1e9);
    ordered_set s;

    cin >> n >> k;

    vector <int> v(n);

    for (auto &it : v) {
        cin >> it;
    }

    for (i = 0; i < k; i++) {
        s.insert({v[i], i});
    }

    for (i = k; i < n; i++) {
        min_mex = min(min_mex, get_mex(s));

        s.erase({v[i - k], i - k});
        s.insert({v[i], i});
    }

    min_mex = min(min_mex, get_mex(s));

    cout << min_mex << "\n";

    return 0;
}
