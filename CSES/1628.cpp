#include <bits/stdc++.h>

using namespace std;

#define int long long

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, x, sum, count = 0;
    int i, mask;

    cin >> n >> x;

    vector <int> v1(n / 2), v2((n / 2) + (n % 2)), a, b;

    for (auto &it : v1) {
        cin >> it;
    }

    for (auto &it : v2) {
        cin >> it;
    }

    for (mask = 0; mask < (1 << v1.size()); mask++) {
        sum = 0;

        for (i = 0; i < v1.size(); i++) {
            if (mask & (1 << i)) {
                sum += v1[i];
            }
        }

        a.push_back(sum);
    }

    for (mask = 0; mask < (1 << v2.size()); mask++) {
        sum = 0;

        for (i = 0; i < v2.size(); i++) {
            if (mask & (1 << i)) {
                sum += v2[i];
            }
        }

        b.push_back(sum);
    }

    sort(b.begin(), b.end());

    for (auto &it : a) {
        count += upper_bound(b.begin(), b.end(), x - it) - lower_bound(b.begin(), b.end(), x - it);
    }

    cout << count << "\n";

    return 0;
}