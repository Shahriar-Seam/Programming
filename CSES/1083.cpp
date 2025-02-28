#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, i, x = 0, temp;

    cin >> n;

    for (i = 1; i <= n; i++) {
        x ^= i;
    }

    for (i = 1; i < n; i++) {
        cin >> temp;

        x ^= temp;
    }

    cout << x << "\n";

    return 0;
}