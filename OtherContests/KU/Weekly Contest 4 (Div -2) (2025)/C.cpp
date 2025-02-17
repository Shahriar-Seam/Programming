#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q, op, i, count = 0;

    cin >> n >> q;

    vector <int> v(n + 1, 1), indices(n + 1, -1);

    for (i = 1; i <= n; i++) {
        indices[i] = i;
    }

    while (q--) {
        cin >> op;

        if (op == 2) {
            cout << count << "\n";
        }
        else {
            int p, h;

            cin >> p >> h;

            int a = indices[p];

            v[a]--;

            if (v[a] == 1) {
                count--;
            }

            v[h]++;

            indices[p] = h;

            if (v[h] == 2) {
                count++;
            }
        }
    }

    return 0;
}