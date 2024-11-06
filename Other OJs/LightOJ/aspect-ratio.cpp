#include <bits/stdc++.h>

using namespace std;

void solve()
{
    double k, r;

    cin >> k;

    r = sqrt((k * k - 1) / (4 - k * k));

    cout << r << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cout << fixed << setprecision(4);

    int t, i;

    cin >> t;

    for (i = 1; i <= t; i++) {
        cout << "Case " << i << ": ";

        solve();
    }

    return 0;
}