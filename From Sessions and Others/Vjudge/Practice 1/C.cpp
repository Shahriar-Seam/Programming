#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t, n, i, temp, zero, one;
    
    cin >> t;

    while (t--) {
        cin >> n;

        zero = one = 0;

        for (i = 0; i < n; i++) {
            cin >> temp;

            if (temp == 0) {
                zero++;
            }
            else if (temp == 1) {
                one++;
            }
        }

        if (zero <= (n + 1) / 2) {
            cout << 0 << "\n";
        }
        else if ((n == zero + one) && (zero > one) && (one > 0)) {
            cout << 2 << "\n";
        }
        else {
            cout << 1 << "\n";
        }
    }

    return 0;
}