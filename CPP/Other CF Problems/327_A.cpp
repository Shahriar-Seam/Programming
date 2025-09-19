#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, i, j, k, cnt = 0;

    cin >> n;

    vector <int> v(n), t;

    for (auto &it : v) {
        cin >> it;
    }

    for (i = 0; i < n; i++) {
        for (j = i; j < n; j++) {
            t = v;

            for (k = i; k <= j; k++) {
                if (t[k]) {
                    t[k] = 0;
                }
                else {
                    t[k] = 1;
                }
            }

            cnt = max(cnt, (int) count(t.begin(), t.end(), 1));
        }
    }

    cout << cnt << "\n";

    return 0;
}