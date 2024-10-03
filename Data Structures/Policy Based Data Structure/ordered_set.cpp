#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <functional>
#include <bits/stdc++.h>

using namespace __gnu_pbds;
using namespace std;

typedef tree <int, null_type, less <int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

int main()
{
    ordered_set p;

    p.insert(5);
    p.insert(2);
    p.insert(6);
    p.insert(4);

    for (auto it : p) {
        cout << it << " ";
    }

    cout << "\n\n";

    cout << "The value at 3rd index : " << *p.find_by_order(3) << "\n";

    cout << "The index of number 6 : " << p.order_of_key(6) << "\n";

    cout << "The index of number seven : " << p.order_of_key(-1) << "\n";
}