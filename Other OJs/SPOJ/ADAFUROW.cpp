#include <bits/stdc++.h>

using namespace std;

const int sz = 2e4 + 5;

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int q, x, y, i;
    char op;

    cin >> q;

    vector <bitset <sz> > v(sz);

    while (q--) {
        cin >> op >> x >> y;

        if (op == '+') {
            v[x][y] = 1;
        }
        else if (op == '-') {
            v[x][y] = 0;
        }
        else if (op == 'v') {
            cout << (v[x] | v[y]).count() << "\n";
        }
        else if (op == '^') {
            cout << (v[x] & v[y]).count() << "\n";
        }
        else if (op == '!') {
            cout << (v[x] ^ v[y]).count() << "\n";
        }
        else if (op == '\\') {
            cout << (v[x] ^ (v[x] & v[y])).count() << "\n";
        }
    }

    return 0;
}