#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout << setprecision(15);

    int n, i, j;

    cin >> n;

    vector <double> ans(n + 1, 0), prev(n + 1, 0);

    prev[0] = ans[0] = -1;
    prev[1] = ans[1] = 1;

    for (i = 2; i <= n; i++) {
        ans[0] = -i;
        ans[i] = i;

        for (j = 1; j < i; j++) {
            ans[j] = (j * prev[j] + (i - j) * prev[j - 1]) / (i * 1.0);
        }

        for (j = 0; j <= i; j++) {
            prev[j] = ans[j];
        }
    }

    for (i = 0; i <= n; i++) {
        cout << ans[i];

        if (i != n) {
            cout << " ";
        }
        else {
            cout << "\n";
        }
    }

    return 0;
}