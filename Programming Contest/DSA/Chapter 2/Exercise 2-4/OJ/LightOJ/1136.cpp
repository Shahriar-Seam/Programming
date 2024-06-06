#include <bits/stdc++.h>

using namespace std;

long long _count(int n)
{
    int _cnt;

    if (n == 0) {
        return 0;
    }

    if (n % 3 == 0) {
        _cnt = n / 3;
    }
    else {
        _cnt = n / 3 + 1;
    }

    return n - _cnt;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long t, a, b, i, j, cnt;

    cin >> t;

    for (j = 1; j <= t; j++) {
        cin >> a >> b;

        cnt = _count(b) - _count(a - 1);

        cout << "Case " << j <<": " << cnt << "\n";
    }

    return 0;
}