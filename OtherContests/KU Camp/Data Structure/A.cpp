#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <functional>
#include <bits/stdc++.h>

using namespace std;
using namespace __gnu_pbds;

typedef tree <pair <int, int>, null_type, greater <pair <int, int> >, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, ind, b, i, r, count = 0;
    ordered_multiset B, I, R;

    cin >> n;

    vector <vector <int> > v(n, vector <int> (3));

    for (ind = 0; ind < n; ind++) {
        cin >> b;

        v[ind][0] = b;

        B.insert({b, ind});
    }

    for (ind = 0; ind < n; ind++) {
        cin >> i;

        v[ind][1] = i;

        I.insert({i, ind});
    }

    for (ind = 0; ind < n; ind++) {
        cin >> r;

        v[ind][2] = r;

        R.insert({r, ind});
    }

    for (ind = 0; ind < n; ind++) {
        b = v[ind][0];
        i = v[ind][1];
        r = v[ind][2];

        int bb = B.order_of_key({b, n + 1});
        int ii = I.order_of_key({i, n + 1});
        int rr = R.order_of_key({r, n + 1});

        if ((bb > 0 && ii > 0 && rr > 0)) {
            count++;

            B.erase(B.find_by_order(bb));
            I.erase(I.find_by_order(ii));
            R.erase(R.find_by_order(rr));
        }
    }

    cout << count << "\n";

    return 0;
}