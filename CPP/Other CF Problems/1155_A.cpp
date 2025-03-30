#include <bits/stdc++.h>

using namespace std;

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, i, j;
    string s;

    cin >> n >> s;

    for (i = 1, j = 0; i < n; i++) {
        if (s[i] > s[j]) {
            j = i;
        }
        else if (s[i] < s[j]) {
            cout << "YES\n";

            cout << j + 1 << " " << i + 1 << "\n";

            return 0;
        }
    }

    cout << "NO\n";

    return 0;
}