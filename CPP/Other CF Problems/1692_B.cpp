#include <bits/stdc++.h>

using namespace std;

int main()
{
    set <int> s;
    int t, tt, n, d, i;

    cin >> t;

    while (t--) {
        cin >> tt;

        for (i = 0; i < tt; i++) {
            cin >> n;

            s.insert(n);
        }

        d = s.size();

        if ((d % 2) == (tt % 2)) {
            cout << d << "\n";
        }
        else {
            cout << d - 1 << "\n";
        }

        s.clear();
    }

    return 0;
}