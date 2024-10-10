#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <functional>
#include <bits/stdc++.h>

using namespace std;
using namespace __gnu_pbds;

typedef tree <int, null_type, greater <int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, temp;
    ordered_set s;

    cin >> n;

    while (n--) {
        cin >> temp;

        cout << s.order_of_key(temp) << " ";

        s.insert(temp);
    }

    return 0;
}