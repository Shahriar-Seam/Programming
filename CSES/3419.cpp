#include <bits/stdc++.h>

using namespace std;

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, i, j;

    cin >> n;

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            cout << (i ^ j) << " ";
        }

        cout << "\n";
    }

    return 0;
}