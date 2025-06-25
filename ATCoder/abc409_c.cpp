#include <bits/stdc++.h>

using namespace std;

#define int long long

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, l, sum = 0, count = 0, i, j;

    cin >> n >> l;

    vector <int> v(n - 1), points(l, 0);

    points[0] = 1;

    for (auto &it : v) {
        cin >> it;

        sum = (sum + it) % l;

        points[sum]++;
    }

    if (l % 3 != 0) {
        cout << 0 << "\n";
    }
    else {
        for (i = 0; i < l; i++) {
            if ((i + 2 * l / 3) < l) {
                count += points[i] * points[i + l / 3] * points[i + 2 * l / 3];
            }
        }

        cout << count << "\n";
    }

    return 0;
}