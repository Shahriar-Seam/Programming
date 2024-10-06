#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long n, i, min_val = LONG_LONG_MAX;
    long long max_sum = LONG_LONG_MIN;

    cin >> n;

    vector <long long> v(n), prefix(n + 1, 0);

    for (auto &it : v) {
        cin >> it;
    }

    for (i = 0; i < n; i++) {
        prefix[i + 1] = prefix[i] + v[i];
    }

    for (i = 0; i < n; i++) {
        min_val = min(min_val, prefix[i]);

        max_sum = max(max_sum, prefix[i + 1] - min_val);
    }

    cout << max_sum << "\n";

    return 0;
}