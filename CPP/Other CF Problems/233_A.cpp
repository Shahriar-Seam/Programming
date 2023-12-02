#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, i;

    cin >> n;

    if (n % 2 == 0) {
        for (i = 1; i <= n; i += 2) {
            cout << i + 1 << " " << i << " ";
        }
    }
    else {
        cout << -1;
    }

    return 0;
}