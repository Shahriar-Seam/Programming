#include <bits/stdc++.h>

using namespace std;

#define int long long

int bin_search(vector <int> &v, int k)
{
    int l = 0, r = v.size() - 1, m, index = -1;

    while (l <= r) {
        m = l + (r - l) / 2;
        
        if (v[m] >= k) {
            index = m;

            r = m - 1;
        }
        else {
            l = m + 1;
        }
    }

    return index;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q, k, i;

    cin >> n >> q;

    vector <int> v(n), counter(n);

    for (auto &it : v) {
        cin >> it;
    }

    for (i = 0; i < n; i++) {
        counter[i] = v[i] - i - 1;
    }

    while (q--) {
        cin >> k;

        if (k > counter[n - 1]) {
            cout << v[n - 1] + k - counter[n - 1] << "\n";
        }
        else {
            i = bin_search(counter, k);

            cout << v[i] - counter[i] + k - 1 << "\n";
        }
    }

    return 0;
}