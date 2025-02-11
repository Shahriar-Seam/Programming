#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, num1, num2;

    cin >> n;

    vector <int> x(n);

    for (auto &it : x) {
        cin >> it;
    }

    cout << "? " << 1 << " " << n << "\n";

    cout.flush();

    cin >> num1;

    cout << "? " << n << " " << 1 << "\n";

    cout.flush();

    cin >> num2;

    if (num1 == num2 && num1 >= abs(x[0] - x[n - 1])) {
        cout << "! B\n";
    }
    else {
        cout << "! A\n";
    }

    cout.flush();
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