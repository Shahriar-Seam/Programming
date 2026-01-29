#include <bits/stdc++.h>

using namespace std;

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int l = 1, r = 1e9, y, x;
    string response;

    while (l <= r) {
        y = (l + r) / 2;

        cout << "? " << y << endl;
        cin >> response;

        if (response == "NO") {
            x = y;

            r = y - 1;
        }
        else {
            l = y + 1;
        }
    }

    cout << "! " << x << "\n";

    return 0;
}