#include <bits/stdc++.h>

using namespace std;

#define int long long

// https://www.geeksforgeeks.org/dsa/divide-a-sorted-array-in-k-parts-with-sum-of-difference-of-max-and-min-minimized-in-each-part/

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, i, sum = 0;

    cin >> n >> m;

    vector <int> v(n), temp;

    for (auto &it : v) {
        cin >> it;
    }

    sort(v.begin(), v.end());

    auto it = unique(v.begin(), v.end());

    v.resize(distance(v.begin(), it));

    n = v.size();

    if (m >= n) {
        cout << 0 << "\n";
    }
    else {
        for (i = 1; i < n; i++) {
            temp.push_back(v[i] - v[i - 1]);
        }

        sort(temp.begin(), temp.end(), greater <> ());

        for (i = 0; i < m - 1; i++) {
            sum += temp[i];
        }

        cout << v[n - 1] - v[0] - sum << "\n";
    }

    return 0;
}