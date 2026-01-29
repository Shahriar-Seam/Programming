#include <bits/stdc++.h>

using namespace std;

#define int long long

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, i, j, prv, now, len = 1, count = 0, f;
    deque <int> p;

    cin >> n >> m;

    vector <vector <int> > v(m, vector <int> (n + 1, -1));

    if (m == 1) {
        cout << (n * (n + 1)) / 2 << "\n";

        return 0;
    }

    for (i = 0; i < m; i++) {
        prv = 0;

        for (j = 0; j < n; j++) {
            cin >> now;

            if (i == 0) {
                p.push_back(now);
            }

            v[i][prv] = now;

            prv = now;
        }
    }

    now = p.front();

    while (!p.empty()) {
        f = 1;

        p.pop_front();

        for (j = 1, prv = v[0][now]; j < m; j++) {
            if (v[j][now] != prv) {
                f = 0;

                break;
            }
        }

        count += len;

        if (!f) {
            len = 1;
            now = p.front();
        }
        else {
            len++;
            now = prv;
        }
    }

    cout << count << "\n";

    return 0;
}