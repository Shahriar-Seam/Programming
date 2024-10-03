#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/functional>
#include <bits/stdc++.h>

using namespace std;
using namespace __gnu_pbds;

typedef tree<pair <long long, int>, null_type, less <pair <long long, int> >, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

void solve()
{
    long long n, q, i, x;
    char op;
    ordered_set s;
    int c = 0;

    cin >> n >> q;

    s.insert({n, c++});

    for (i = 0; i < q; i++) {
        cin >> op >> x;

        if (op == 'C') {
            auto index = s.upper_bound({x, 0});

            if (s.size() == 1) {
                s.erase(index);

                s.insert({x, c++});
                s.insert({n - x, c++});
            }
            else {
                long long temp = (*--index).first;

                s.erase(index);

                s.insert({n - x, c++});
                s.insert({temp - n + x, c++});
            }
        }
        else {
            cout << (*s.find_by_order(x - 1)).first << "\n";
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t, i;

    cin >> t;

    for (i = 1; i <= t; i++) {
        cout << "Case " << i << ":\n";

        solve();
    }

    return 0;
}