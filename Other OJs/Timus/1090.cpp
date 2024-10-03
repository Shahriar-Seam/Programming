#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/functional>
#include <bits/stdc++.h>

using namespace __gnu_pbds;
using namespace std;

typedef tree<int, null_type, greater <int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k, i, j, temp, max_row = 1, ma = 0;
    ordered_set s;

    cin >> n >> k;

    vector <int> v(k, 0);

    for (i = 0; i < k; i++) {
        s.clear();

        for (j = 0; j < n; j++) {
            cin >> temp;

            v[i] += s.order_of_key(temp);

            s.insert(temp);
        }
    }

    for (i = 0; i < k; i++) {
        if (v[i] > ma) {
            ma = v[i];

            max_row = i + 1;
        }
    }

    cout << max_row << "\n";

    return 0;
}