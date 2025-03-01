#include <bits/stdc++.h>

using namespace std;

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q, i;
    segment_tree st;

    cin >> n >> q;

    for (i = 1; i <= n; i++) {
        arr[i] = i;
    }

    while (q--) {
        int op, a, b;

        cin >> op;

        if (op == 1) {
            cin >> a >> b;
        }
        else if (op == 2) {
            cin >> a >> b;

            swap(mp[a], mp[b]);

            for (auto it : mp[a]) {
                indices[it] = a;
            }

            for (auto it : mp[b]) {
                indices[it] = b;
            }
        }
        else {
            cin >> a;

            cout << indices[a] << "\n";
        }
    }

    return 0;
}