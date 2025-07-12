#include <bits/stdc++.h>

using namespace std;

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, l, r, cnt = 0, a, b;

    cin >> n >> l >> r;

    while (n--) {
        cin >> a >> b;

        cnt += (a <= l && b >= r);
    }

    cout << cnt << "\n";

    return 0;
}