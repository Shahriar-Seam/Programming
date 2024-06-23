#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, s, i, mask, subset_sum;

    cin >> n >> s;

    vector <int> v(n);

    for (auto &it : v) {
        cin >> it;
    }

    for (mask = 0; mask < (1 << n); mask++) {
        subset_sum = 0;

        for (i = 0; i < n; i++) {
            if (mask & (1 << i)) {
                subset_sum += v[i];
            }
        }

        if (subset_sum == s) {
            cout << mask << " ";
            puts("Yes");

            return 0;
        }
    }

    puts("No");

    return 0;
}