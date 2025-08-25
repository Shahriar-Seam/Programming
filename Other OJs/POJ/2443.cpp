#include <iostream>
#include <vector>
#include <algorithm>
#include <bitset>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, q, i, j, k, c, x;

    cin >> n;

    vector <bitset <1005> > v(10005);

    for (i = 0; i < n; i++) {
        cin >> c;

        for (j = 0; j < c; j++) {
            cin >> x;

            v[x].set(i);
        }
    }

    cin >> q;

    while (q--) {
        cin >> i >> j;
        
        cout << ((v[i] & v[j]).any() ? "Yes" : "No") << "\n";
    }

    return 0;
}