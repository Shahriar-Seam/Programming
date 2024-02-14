#include <bits/stdc++.h>

using namespace std;

bool is_lucky(int n)
{
    while (n > 0) {
        if ((n % 10 != 4) && (n % 10 != 7)) {
            return false;
        }

        n /= 10;
    }

    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, f = 0, i;

    cin >> n;

    for (i = 4; i <= n; i++) {
        if ((n % i == 0) && is_lucky(i)) {
            f = 1;
        }
    }

    puts(f ? "YES" : "NO");

    return 0;
}