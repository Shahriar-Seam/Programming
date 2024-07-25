#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int q, p, x;
    vector <int> v;

    cin >> q;

    while (q--) {
        cin >> p;

        if (p == 0) {
            cin >> x;

            v.push_back(x);
        }
        else if (p == 1) {
            cin >> x;

            cout << v[x] << "\n";
        }
        else {
            v.pop_back();
        }
    }

    return 0;
}