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

    int n, m, num, i;
    char l;
    ordered_set s;

    cin >> n >> m;

    for (i = 0; i < m; i++) {
        cin >> l >> num;

        if (l == 'L') {
            cout << num + s.order_of_key({num, i}) << "\n";
        }
        else {
            s.insert({num, i});
        }
    }

    for (auto it : s) {
        cout << it.first << " " << it.second << "\n";
    }

    return 0;
}