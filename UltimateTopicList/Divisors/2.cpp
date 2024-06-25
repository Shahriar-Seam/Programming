#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int a, b, c, cnt = 0, i;

    cin >> a >> b >> c;

    for (i = a; i <= b; i++) {
        if (c % i == 0) {
            cnt++;
        }
    }

    cout << cnt << "\n";

    return 0;
}