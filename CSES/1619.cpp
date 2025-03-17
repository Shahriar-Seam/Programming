#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/functional>
#include <bits/stdc++.h>

using namespace __gnu_pbds;
using namespace std;

typedef tree<pair <int, int>, null_type, less <pair <int, int> >, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

using namespace std;

bool compare(pair <int, int> a, pair <int, int> b) {
    return a.second > b.second;
}

int max(int a, int b)
{
    return a > b ? a : b;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, max_customers = 0, i;
    ordered_set os;

    cin >> n;

    vector<pair <int, int> > v(n);

    for (auto &it : v) {
        cin >> it.first >> it.second;
    }

    sort(v.begin(), v.end(), compare);

    for (i = 0; i < n; i++) {
        max_customers = max(max_customers, 1 + os.order_of_key({v[i].second, 1e9}));

        os.insert({v[i].first, i});
    }

    cout << max_customers << "\n";

    return 0;
}