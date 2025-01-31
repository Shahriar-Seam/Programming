#include <bits/stdc++.h>

using namespace std;

#define int long long

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, i;
    int sum = 0, max_sum;

    cin >> n;

    vector <int> v(n);

    for (auto &it : v) {
        cin >> it;
    }

    max_sum = *max_element(v.begin(), v.end());

    for (i = 0; i < n; i++) {
        sum += v[i];

        max_sum = max(max_sum, sum);

        if (sum < 0) {
            sum = 0;
        }
    }

    cout << max_sum << "\n";

    return 0;
}