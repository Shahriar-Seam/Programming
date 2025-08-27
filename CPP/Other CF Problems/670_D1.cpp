#include <bits/stdc++.h>

using namespace std;

#define int long long

bool possible(vector <int> &a, vector <int> &b, __int128_t m, __int128_t k)
{
    int i;

    for (i = 0; i < a.size(); i++) {
        if (b[i] / a[i] < m) {
            k -= m * a[i] - b[i];
        }
    }

    return k >= 0;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    int l = 0, r = 1e12, m, count = 0;

    cin >> n >> k;

    vector <int> a(n), b(n);

    for (auto &it : a) {
        cin >> it;
    }

    for (auto &it : b) {
        cin >> it;
    }

    while (l <= r) {
        m = l + (r - l) / 2;

        if (possible(a, b, m, k)) {
            l = m + 1;

            count = m;
        }
        else {
            r = m - 1;
        }
    }

    cout << count << "\n";

    return 0;
}