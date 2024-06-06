#include <bits/stdc++.h>

using namespace std;

int is_lucky(int n)
{
    while (n != 0) {
        if ((n % 10 != 4) && (n % 10 != 7)) {
            return 0;
        }

        n /= 10;
    }

    return 1;
}

int main()
{
    int a, b, i, f = 0;

    cin >> a >> b;

    for (i = a; i <= b; i++) {
        if (is_lucky(i)) {
            cout << i << " ";
            f++;
        }
    }

    if (f == 0) {
        cout << -1;
    }

    return 0;
}