#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int l, r, L, R, i, cnt = 0, f = 0;
    int is2 = 0, ot = 0, to = 0;
    int arr[105] = {};

    cin >> l >> r >> L >> R;

    for (i = l; i <= r; i++) {
        arr[i]++;
    }

    for (i = L; i <= R; i++) {
        arr[i]++;
    }

    for (i = min(l, L); i <= max(r, R); i++) {
        if (arr[i] == 2) {
            is2 = 1;
        }
    }

    if (!is2) {
        cout << 1 << "\n";

        return;
    }
    else {
        for (i = 1; i <= max(r, R); i++) {
            if (arr[i - 1] == 1 && arr[i] == 2) {
                ot = 1;
            }
            if (arr[i - 1] == 2 && arr[i] == 1) {
                to = 1;
            }

            cnt += (arr[i] == 2);
        }

        if (to) {
            cnt++;
        }

        if (!ot) {
            cnt--;
        }

        cout << cnt << "\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;

    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}