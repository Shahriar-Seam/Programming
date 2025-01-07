#include <bits/stdc++.h>

using namespace std;

int is_possible(long long n)
{
    if (n == 1) {
        return 1;
    }
    else if ((n % 10) != 0) {
        return 0;
    }
    else if (n % 20 == 0) {
        return is_possible(n / 10) + is_possible(n / 20);
    }

    return is_possible(n / 10);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long t, n;

    cin >> t;

    while (t--) {
        cin >> n;

        cout << (is_possible(n) ? "YES\n" : "NO\n");
    }

    return 0;
}