#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long t, n, product = 1;

    cin >> t;

    while (t--) {
        cin >> n;

        product = (product * n) % (1000000007);
    }

    cout << product;

    return 0;
}