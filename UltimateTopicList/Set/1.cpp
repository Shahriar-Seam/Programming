#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    set <int> s;
    int q, y, x;

    cin >> q;

    while (q--) {
        cin >> y >> x;

        if (y == 1) {
            s.insert(x);
        }
        else if (y == 2) {
            s.erase(x);
        }
        else {
            cout << (s.find(x) == end(s) ? "No" : "Yes") << "\n";
        }
    }

    return 0;
}