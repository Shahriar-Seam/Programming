#include <bits/stdc++.h>

using namespace std;

#define int long long

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, i, count = 0;

    cin >> n;

    vector <int> a(n), b(n), big, small;

    for (auto &it : a) {
        cin >> it;
    }

    for (auto &it : b) {
        cin >> it;
    }

    for (i = 0; i < n; i++) {
        big.push_back(a[i] - b[i]);
        small.push_back(b[i] - a[i]);
    }

    sort(big.begin(), big.end());
    sort(small.begin(), small.end());

    for (i = 0; i < n; i++) {
        count += big.end() - upper_bound(big.begin(), big.end(), small[i]);

        if (small[i] < 0) {
            count--;
        }
    }

    cout << count / 2 << "\n";

    return 0;
}