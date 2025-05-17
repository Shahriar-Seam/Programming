#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, res;

    cin >> n;

    cout << "mul 9\n";

    cout.flush();

    cin >> res;

    cout << "digit\n";

    cout.flush();

    cin >> res;

    cout << "digit\n";

    cout.flush();

    cin >> res;

    cout << "add " << n - 9 << "\n";

    cout.flush();

    cin >> res;

    cout << "!\n";

    cout.flush();

    cin >> res;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int32_t t, i;

    cin >> t;

    for (i = 1; i <= t; i++) {
        // cout << "Case " << i << ": ";

        solve();
    }

    return 0;
}