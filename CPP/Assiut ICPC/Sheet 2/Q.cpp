#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t, n;

    cin >> t;

    while (t--) {
        cin >> n;

        if (n == 0) {
            cout << 0;
        }

        while (n != 0) {
            cout << n % 10 << " ";
            
            n /= 10;
        }

        cout << "\n";
    }

    return 0;
}