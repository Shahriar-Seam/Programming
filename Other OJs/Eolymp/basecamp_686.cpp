#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/functional>
#include <bits/stdc++.h>

using namespace __gnu_pbds;
using namespace std;

typedef tree<int, null_type, less <int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n, i, j;
    char c;
    ordered_set s;

    cin >> n;

    vector <pair <char, int>> v(n);
    vector <int> answer;

    for (j = 0; j < n; j++) {
        cin >> v[j].first >> v[j].second;
    }

    for (j = 0; j < n; j++) {
        c = v[j].first;
        i = v[j].second;

        if (c == '+') {
            if (j > 0 && v[j - 1].first == '?') {
                s.insert((i + answer.back()) % int(1e9));
            }
            else {
                s.insert(i);
            }
        }
        else {
            auto num = s.lower_bound(i);

            answer.push_back(num == s.end() ? -1 : *num);
        }
    }

    for (auto it : answer) {
        cout << it << "\n";
    }
}
