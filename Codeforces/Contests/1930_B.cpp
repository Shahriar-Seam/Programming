#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t, n, i;

    cin >> t;

    while (t--) {
        cin >> n;

        for (i = 1; i <= n / 2; i++) {
            cout << min(i, n - i + 1) << " " << max(i, n - i + 1) << " ";
        }

        if (n % 2 == 1) {
            cout << (n + 1) / 2;
        }

        cout << "\n";
    }

    return 0;
}