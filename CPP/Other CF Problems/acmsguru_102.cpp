#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, i, cnt = 0;

    cin >> n;

    for (i = 1; i < n; i++) {
        if (gcd(n, i) == 1) {
            cnt++;
        }
    }

    cout << cnt;

    return 0;
}