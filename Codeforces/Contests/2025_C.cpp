#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <functional>
#include <bits/stdc++.h>

using namespace std;
using namespace __gnu_pbds;

typedef tree <pair <int, int>, null_type, less <pair <int, int> >, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

void solve()
{
    int n, k, i, count = 1, max_count = 1;
    ordered_set s;
    set <int> ss;

    cin >> n >> k;

    vector <int> v(n);

    for (auto &it : v) {
        cin >> it;
    }

    sort(v.begin(), v.end());

    s.insert({v[0], 0});
    ss.insert(v[0]);

    for (i = 1; i < n; i++) {
        max_count = max(max_count, count);
        
        s.insert({v[i], i});
        ss.insert(v[i]);

        count++;

        if (v[i] > v[i - 1] + 1) {
            s.clear();
            ss.clear();

            s.insert({v[i], i});
            ss.insert(v[i]);

            count = 1;
        }
        else if ((ss.size() > k)) {
            int small = (*s.find_by_order(0)).first;

            while ((s.size() > 0) && ((*s.begin()).first == small)) {
                s.erase(s.begin());
            }

            ss.erase(ss.begin());

            count = s.size();
        }
    }

    max_count = max(max_count, count);

    cout << max_count << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;

    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}