#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t, n, f;

    cin >> t;

    while (t--) {
        cin >> n;

        f = 0;

        while (n > 100) {
            if ((n % 11 == 0) || (n % 111 == 0)) {
                f = 1;
                break;
            }

            else {
                n -= 111;
            }
        }

        if (n % 11 == 0) {
            f = 1;
        }

        f ? cout << "YES\n" : cout << "NO\n";
    }

    return 0;
}