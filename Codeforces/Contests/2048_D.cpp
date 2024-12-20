#include <bits/stdc++.h>

using namespace std;

#define int long long

int bin_search(vector <int> &v, int k)
{
    int l = 0, r = v.size() - 1, m, index = 0;

    while (l <= r) {
        m = (l + r) / 2;

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

void solve()
{
    int n, m, i, j, r_k, i_k, sum;

    cin >> n >> m;

    vector <int> a(n), b(m), v;

    for (auto &it : a) {
        cin >> it;
    }

    for (auto &it : b) {
        cin >> it;
    }
    
    r_k = a[0];

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    for (i = n - 1; i >= 0; i--) {
        if (a[i] == r_k) {
            i_k = i;

            break;
        }
    }

    // k == 1
    for (i = 0; i < m; i++) {
        int temp = bin_search(a, b[i]);

        if (temp > i_k) {
            v.push_back(n - temp + 1);
        }
        else {
            v.push_back(1);
        }
    }

    v.push_back(0);

    sort(v.begin(), v.end());

    for (i = 1; i <= m; i++) {
        sum = 0;

        for (j = i; j <= m; j += i) {
            sum += v[j];
        }

        cout << sum << " ";
    }

    cout << "\n";
}

int32_t main()
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