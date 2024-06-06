#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t, n, i, num, even, odd;

    cin >> t;

    while (t--) {
        cin >> n;

        even = odd = 0;

        for (i = 0; i < n; i++) {
            cin >> num;

            (num % 2 == 0) ? even++ : odd++;
        }

        (n % 2 == 0) ? cout << abs(even - odd) / 2 << "\n" : cout << -1 << "\n";
    }

    return 0;
}