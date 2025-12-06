#include <bits/stdc++.h>

using namespace std;

#define int long long

int bin_search(vector <int> &v, int k)
{
    int l = 0, r = v.size() - 1, m;

    while (l <= r) {
        m = (l + r) / 2;

        if (v[m] == k) {
            return m;
        }
        else if (v[m] > k) {
            r = m - 1;
        }
        else {
            l = m + 1;
        }
    }

    return v[m] == k ? m : -1;
}

void solve()
{
    int n, k, index, i, j, f, c;

    cin >> n >> k;

    vector <int> v(n), b;
    set <int> s;
    
    for (auto &it : v) {
        cin >> it;
        
        s.insert(it);
    }
    
    v.clear();
    
    for (auto &it : s) {
        v.push_back(it);
    }
    
    n = v.size();
    vector <int> marked(n, 0);

    for (i = 0; i < n; i++) {
        if (marked[i]) {
            continue;
        }

        f = 1;
        c = 0;

        for (j = 1; v[i] * j <= k; j++) {
            index = bin_search(v, v[i] * j);

            if (index == -1) {
                f = 0;

                break;
            }
            else {
                if (!marked[index]) {
                    c++;
                }

                marked[index]++;
            }
        }

        if (f && c) {
            b.push_back(v[i]);
        }
        else {
            for (j = 1; v[i] * j <= k; j++) {
                index = bin_search(v, v[i] * j);

                if (index == -1) {
                    break;
                }
                else {
                    marked[index]--;
                }
            }
        }
    }

    if (b.empty() || (count(marked.begin(), marked.end(), 0LL) > 0)) {
        cout << -1 << "\n";
    }
    else {
        cout << b.size() << "\n";

        for (auto &it : b) {
            cout << it << " ";
        }

        cout << "\n";
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