#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, clicks = 0;

    cin >> n >> m;

    while (n != m) {
        if ((m > n) && (m % 2 == 0)) {
            m /= 2;
            clicks++;
        }
        else {
            m++;
            clicks++;
        }
    }

    cout << clicks << "\n";

    return 0;
}