#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t, cnt, f;
    long long n;

    cin >> t;

    while (t--) {
        cin >> n;

        cnt = 0;
        f = 1;

        while (n > 1) {
            if (n % 2 == 0) {
                n /= 2;
            }
            else if (n % 3 == 0) {
                n = 2 * n / 3;
            }
            else if (n % 5 == 0) {
                n = 4 * n / 5;
            }

            if (n % 2 != 0 && n % 3 != 0 && n % 5 != 0 && n != 1) {
                f = 0;
                break;
            }

            cnt++;
        }

        f ? cout << cnt << "\n" : cout << -1 << "\n";
    }

    return 0;
}