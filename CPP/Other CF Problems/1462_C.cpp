#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t, n, i, j;
    char s[10];

    cin >> t;

    while (t--) {
        cin >> n;

        if (n > 45) {
            cout << -1 << "\n";
            continue;
        }
        else {
            for (i = 9, j = 0; ; i--) {
                if (n - i <= 0) {
                    break;
                }

                s[j++] = i + '0';

                n -= i;
            }

            s[j++] = n + '0';
            s[j++] = '\0';
        }

        cout << strrev(s) << "\n";
    }

    return 0;
}