#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long n, r, c;

    cin >> n;

    r = n / 4;

    if (r % 2 == 0) {
        c = n % 4;
    }
    else {
        c = 3 - n % 4;
    }

    cout << r << " " << c;

    return 0;
}