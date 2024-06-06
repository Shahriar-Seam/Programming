#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, l, r, i;

    cin >> n >> l >> r;

    for (i = 1; i < l; i++) {
        cout << i << " ";
    }

    for (i = r; i >= l; i--) {
        cout << i << " ";
    }

    for (i = r + 1; i <= n; i++) {
        cout << i << " ";
    }

    return 0;
}