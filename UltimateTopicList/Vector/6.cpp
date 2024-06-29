#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q, y;

    cin >> n;

    vector <int> v(n);

    for (auto &it : v) {
        cin >> it;
    }

    cin >> q;

    while (q--) {
        cin >> y;

        auto it = lower_bound(begin(v), end(v), y);

        if (y == *it) {
            cout << "Yes " << it - begin(v) + 1 << "\n";
        }
        else {
            cout << "No " << it - begin(v) + 1 << "\n";
        }
    }

    return 0;
}