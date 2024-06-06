#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t, n, k, a, b, i;

    cin >> t;

    while (t--) {
        cin >> n >> k;

        if (k % 4 == 0) {
            cout << "NO\n";
        }
        else {
            cout << "YES\n";

            if (k % 2 == 1) {
                for (i = 1; i < n; i += 2) {
                    cout << i << " " << i + 1 << "\n";
                }
            }
            else {
                for (i = 2; i <= n; i += 2) {
                    if (i % 4 == 0) {
                        cout << i - 1 << " " << i << "\n";
                    }
                    else {
                        cout << i << " " << i - 1 << "\n";
                    }
                }
            }
        }
    }

    return 0;
}