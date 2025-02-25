#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/functional>
#include <bits/stdc++.h>

using namespace __gnu_pbds;
using namespace std;

typedef tree<int, null_type, less_equal <int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

int inversion_count(vector <int> &v)
{
    int i, n = v.size(), inv = 0;
    ordered_set os;

    for (i = n - 1; i >= 0; i--) {
        inv += (int) os.order_of_key(v[i]);

        os.insert(v[i]);
    }

    return inv;
}

void solve()
{
    int n, i, j, k, min_inv = 1e9, a = 1, b = 1;
    ordered_set os;

    cin >> n;

    vector <int> v(n), indices(n, 0), temp(n);

    for (auto &it : v) {
        cin >> it;
    }

    min_inv = inversion_count(v);

    for (i = 0; i < n; i++) {
        j = i + 1;

        while (j <= n) {
            if (j < n && v[j] < v[i]) {
                j++;
                
                continue;
            }

            for (k = 0; k < i; k++) {
                temp[k] = v[k];
            }

            for (k = i + 1; k < j; k++) {
                temp[k - 1] = v[k];
            }

            temp[k - 1] = v[i];

            for (k; k < n; k++) {
                temp[k] = v[k];
            }

            int inv = inversion_count(temp);

            // cout << i + 1 << " " << j << " " << inv <<": ";
            // for (auto it : temp) {
            //     cout << it << " ";
            // }
            // cout << "\n";

            if (min_inv > inv) {
                min_inv = inv;

                a = i + 1;
                b = j;
            }

            j++;
        }
    }

    cout << a << " " << b << "\n";
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int32_t t, i;

    cin >> t;

    for (i = 1; i <= t; i++) {
        // cout << "Case " << i << ": ";

        solve();
    }

    return 0;
}