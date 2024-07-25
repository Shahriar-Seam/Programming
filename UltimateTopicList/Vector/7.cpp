#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q, type, x, t, last_read = 0, total = 0, v_size = 0, i;

    cin >> n >> q;

    map <int, int> mp;
    vector <int> v;

    while (q--) {
        cin >> type;

        if (type == 1) {
            cin >> x;

            v.push_back(x);
            v_size++;
            mp[x]++;
            total++;
        }
        else if (type == 2) {
            cin >> x;

            total -= mp[x];
            mp[x] = 0;
        }
        else {
            cin >> t;

            for (i = 0; i < t; i++) {
                mp[v[i]] = 0;
            }

            total = v_size - t;
        }

        cout << total << "\n";
    }

    return 0;
}

// doesn't work