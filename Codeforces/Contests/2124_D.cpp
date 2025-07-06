#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <functional>
#include <bits/stdc++.h>

using namespace std;
using namespace __gnu_pbds;

typedef tree <pair <int, int>, null_type, less <pair <int, int> >, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

int k_len(vector <int> &v, int k, vector <int> &p)
{
    int l = 0, r = v.size() - 1, count = 0;
    vector <int> L, R;

    while (l < r) {
        if (v[l] == v[r]) {
            count += 2;

            L.push_back(v[l]);
            R.push_back(v[r]);

            l++;
            r--;
        }
        else {
            if (v[l] < v[r]) {
                r--;
            }
            else {
                l++;
            }
        }
    }

    if (l == r) {
        count++;
    }

    for (auto &it : L) {
        p.push_back(it);
    }

    reverse(R.begin(), R.end());

    for (auto &it : R) {
        p.push_back(it);
    }

    return count;
}

bool is_palindrome(vector <int> &v)
{
    int i, n = v.size();

    for (i = 0; i < n / 2; i++) {
        if (v[i] != v[n - i - 1]) {
            return false;
        }
    }

    return true;
}

void solve()
{
    int n, k, i, j, f = 0;
    ordered_set os;

    cin >> n >> k;

    vector <int> v(n), p, temp;

    for (i = 0; i < n; i++) {
        cin >> v[i];
        
        os.insert({v[i], i});
    }

    int count = k_len(v, k, p);

    // for (auto &it : v) {
    //     cout << it << " ";
    // }
    // cout << "\n";

    // for (auto &it : p) {
    //     cout << it << " ";
    // }
    // cout << "\n";

    i = j = 0;

    while (i < p.size() && j < v.size()) {
        if (p[i] == v[j]) {
            i++;
            j++;
        }
        else {
            if (os.order_of_key({v[j], j}) >= k - 1) {
                os.erase({v[j], j});

                j++;
            }
            else {
                j++;

                f++;
            }
        }
    }

    while (j < v.size()) {
        if (os.order_of_key({v[j], j}) >= k - 1) {
            os.erase({v[j], j});

            j++;
        }
        else {
            j++;

            f++;
        }
    }

    for (i = 0; i < n; i++) {
        if (os.find({v[i], i}) != os.end()) {
            temp.push_back(v[i]);
        }
    }

    // for (auto &it : p) {
    //     cout << it << " ";
    // }
    // cout << "\n";
    
    // for (auto &it : temp) {
    //     cout << it << " ";
    // }
    // cout << "\n";

    // cout << count << " " << k << " ";

    // cout << f << "\n";

    // for (auto &it : os) {
    //     cout << it.first << " " << it.second << "\n";
    // }

    if (is_palindrome(temp) && f <= 2 && count >= k - 1) {
        cout << "YES\n";
    }
    else {
        cout << "NO\n";
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int32_t t, i;

    cin >> t;

    for (i = 1; i <= t; i++) {
        // cout << "Case " << i << ": ";

        solve();
    }

    return 0;
}