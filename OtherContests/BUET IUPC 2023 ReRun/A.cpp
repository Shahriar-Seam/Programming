#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/functional>
#include <bits/stdc++.h>

using namespace __gnu_pbds;
using namespace std;

typedef tree<pair <long long, long long>, null_type, greater <pair <long long, long long> >, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

void solve()
{
    long long n, i, satisfaction = 0;
    string s;
    ordered_set p, c;

    cin >> n >> s;

    vector <int> v(n);

    for (auto &it : v) {
        cin >> it;
    }

    for (i = 0; i < s.size(); i++) {
        if (s[i] == 'P') {
            p.insert({v[i], i});
        }
        else {
            c.insert({v[i], i});
        }
    }

    while (!c.empty()) {
        auto it_1 = c.find_by_order(0);
        auto it_2 = p.find_by_order(0);
        i = 0;

        while ((*it_1).second < (*it_2).second) {
            i++;

            it_2 = p.find_by_order(i);
        }

        satisfaction += (*it_1).first * (*it_2).first;

        c.erase(it_1);
        p.erase(it_2);
    }

    cout << satisfaction << "\n";
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