#include <bits/stdc++.h>

using namespace std;

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k, t, count = 0;

    cin >> n >> k;

    while (n--) {
        cin >> t;

        count += (t % k == 0);
    }

    cout << count << "\n";

    return 0;
}