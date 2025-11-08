#include <bits/stdc++.h>

using namespace std;

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, k, i, j, x, f, yn = 1;

    cin >> n >> m;

    vector <vector <bool> > p(n + 1, vector <bool> (m + 1, false));

    for (i = 1; i <= m; i++) {
        cin >> k;

        for (j = 0; j < k; j++) {
            cin >> x;

            p[x][i] = true;
        }
    }

    for (i = 1; i <= n; i++) {
        for (j = i + 1; j <= n; j++) {
            f = 0;

            for (k = 1; k <= m; k++) {
                if (p[i][k] && p[j][k]) {
                    f = 1;

                    break;
                }
            }

            if (!f) {
                yn = 0;

                break;
            }
        }

        if (!yn) {
            break;
        }
    }

    cout << (yn ? "Yes" : "No") << "\n";

    return 0;
}