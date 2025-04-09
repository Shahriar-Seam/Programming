#include <bits/stdc++.h>

using namespace std;

#define int long long

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, sum = 0, sq_sum = 0, sum_sq_diff = 0;

    cin >> n;

    vector <int> v(n);

    for (auto &it : v) {
        cin >> it;

        sum += it;

        sq_sum += it * it;
    }

    sum_sq_diff = (n - 1) * sq_sum;

    for (auto it : v) {
        sum_sq_diff -= it * (sum - it);
    }

    cout << sum_sq_diff << "\n";

    return 0;
}