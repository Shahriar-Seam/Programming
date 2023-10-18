#include <bits/stdc++.h>

using namespace std;

int is_prime(int n)
{
    int i, root = sqrt(n);

    if (n < 2) {
        return 0;
    }
    else if (n == 2) {
        return 1;
    }
    else if (n % 2 == 0) {
        return 0;
    }

    for (i = 3; i <= root; i += 2) {
        if (n % i == 0) {
            return 0;
        }
    }

    return 1;
}

int main()
{
    int n, i;

    cin >> n;

    for (i = 2; i <= n; i++) {
        if (is_prime(i)) {
            cout << i << " ";
        }
    }

    return 0;
}