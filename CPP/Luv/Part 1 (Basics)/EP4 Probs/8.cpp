#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, i, cnt;

    cin >> n;

    if (n % 2 == 1) {
        cnt = 0;
    }
    else if (n % 4 == 0) {
        cnt = n / 4 - 1;
    }
    else {
        cnt = n / 4;
    }

    cout << cnt;

    return 0;
}