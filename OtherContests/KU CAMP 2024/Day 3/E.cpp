#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <functional>
#include <bits/stdc++.h>

using namespace std;
using namespace __gnu_pbds;

typedef tree <pair <long long, long long>, null_type, less <pair <long long, long long> >, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

void add(ordered_set &os, long long i) {
    
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    char op;
    ordered_set os;
    long long prev;

    cin >> n;

    while (n--) {
        cin >> op;

        if (op == '+') {
            long long i;
            
            cin >> i;

            if (prev != -1) {
                add(os, prev + i);
            }
            else {
                add(os, i);
            }

            prev = -1;
        }
        else {
            int l, r;

            cin >> l >> r;

            prev = get(l, r);

            cout << prev << "\n";
        }
    }

    return 0;
}