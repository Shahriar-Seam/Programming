#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q, type, y;
    string x;
    map <string, long long> mp;

    cin >> n >> q;

    while (n--) {
        cin >> x >> y;

        mp[x] = 1LL * y;
    }

    while (q--) {
        cin >> type >> x;

        if (type == 1) {
            cin >> y;

            mp[x] += 1LL * y;
        }
        else {
            cout << mp[x] << "\n";
        }
    }

    return 0;
}