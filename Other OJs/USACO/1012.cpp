#include <bits/stdc++.h>

using namespace std;

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("breedflip.in", "r", stdin);
    freopen("breedflip.out", "w", stdout);

    int n, i, count = 0;
    string a, b;

    cin >> n >> a >> b;

    for (i = 0; i < n; ) {
        if (a[i] == b[i]) {
            i++;
        }
        else {
            while (i < n && a[i] != b[i]) {
                i++;
            }

            count++;
        }
    }

    cout << count << "\n";

    return 0;
}