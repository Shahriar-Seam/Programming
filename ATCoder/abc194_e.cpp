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

    clock_t start, end; // To store clock ticks, clock tick is the smallest unit of time that can be measured by the clock
    start = clock(); // Start the clock
    
    int n, k, i, min_mex = int(1e9);
    ordered_set s;

    // cin >> n >> k;
    n = 7;
    k = 3;

    // vector <int> v(n);
    vector <int> v = {0, 0, 1, 2, 0, 1, 0};

    // for (auto &it : v) {
    //     cin >> it;
    // }

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

    end = clock(); // End the clock
  double time_taken = (double)(end - start) / CLOCKS_PER_SEC; // Calculate the time taken, CLOCKS_PER_SEC is the number of clock ticks per second
  cout << "Time taken by program is : " << fixed << setprecision(5) << time_taken << " sec" << endl;

    return 0;
}
