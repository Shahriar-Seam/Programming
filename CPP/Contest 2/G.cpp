#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long t, n, s, i;

    cin >> t;

    while (t--) {
        cin >> n >> s;

        if ((n <= ceil(s / 2.0))) {
            if (n * (n + 1) / 2 >= s) {
                for (i = n; i > 0; i--) {
                    
                }
            }
            else {
                cout << -1 << "\n";
            }
        }
        else {
            if (s % 2 == 0) {
                cout << s / 2 - 1 << " " << s / 2 + 1 << "\n";
            }
            else {
                cout << s / 2 << " " << s / 2 + 1 << "\n";
            }
        }
    }

    return 0;
}