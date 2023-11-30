#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t, n, rev;

    cin >> t;

    while (t--) {
        cin >> n;

        rev = 0;

        while (n != 0) {
            rev *= 10;
            rev += n % 10;
            n /= 10;
        }

        cout << rev << endl;
    }

    return 0;
}