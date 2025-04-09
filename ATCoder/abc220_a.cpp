#include <bits/stdc++.h>

using namespace std;

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int a, b, c, m;

    cin >> a >> b >> c;

    m = ((a + c - 1) / c) * c;

    if (m > b) {
        m = -1;
    }

    cout << m << "\n";

    return 0;
}