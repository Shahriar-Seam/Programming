#include <bits/stdc++.h>

using namespace std;

int main()
{
    int a, b, c, d, m;

    cin >> a >> b >> c >> d;

    m = (a % 100) * (b % 100) * (c % 100) * (d % 100);
    m = m % 100;

    if (m < 10) {
        cout << "0" << m;
    }
    else {
        cout << m;
    }

    return 0;
}