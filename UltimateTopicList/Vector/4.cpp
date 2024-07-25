#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q, p, t, x;

    cin >> n >> q;

    vector <vector <int> > v(n, vector <int>());

    while (q--) {
        cin >> p;

        if (p == 0) {
            cin >> t >> x;

            v[t].push_back(x);
        }
        else if (p == 1) {
            cin >> t;

            int temp = v[t].size();
            for (auto it : v[t]) {
                cout << it;

                if (--temp) {
                    cout << " ";
                }
            }

            cout << "\n";
        }
        else {
            cin >> t;

            v[t].clear();
        }
    }

    return 0;
}