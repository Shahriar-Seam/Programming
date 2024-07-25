#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int q, type, y;
    string x;
    map <string, int> mp;

    cin >> q;

    while (q--) {
        cin >> type >> x;

        if (type == 1) {
            cin >> y;

            mp[x] += y;
        }
        else if (type == 2) {
            mp[x] = 0;
        }
        else {
            cout << mp[x] << "\n";
        }
    }

    return 0;
}