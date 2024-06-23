#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long n, mask, i, sum1, sum2, min_diff = INT_MAX;
    
    cin >> n;

    vector <long long> v(n);

    for (auto &it : v) {
        cin >> it;
    }

    for (mask = 0; mask <= (1 << n); mask++) {
        sum1 = sum2 = 0;

        for (i = 0; i < n; i++) {
            if (mask & (1 << i)) {
                sum1 += v[i];
            }
            else {
                sum2 += v[i];
            }
        }

        min_diff = min(min_diff, abs(sum1 - sum2));
    }

    cout << min_diff;

    return 0;
}