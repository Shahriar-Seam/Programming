#include <bits/stdc++.h>

using namespace std;

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cout << fixed << setprecision(10);

    int n, h, i;

    cin >> n >> h;

    for (i = 1; i < n; i++) {
        cout << h * sqrt(i * 1.0 / n) << " ";
    }

    cout << "\n";

    return 0;
}