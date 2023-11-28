#include <bits/stdc++.h>

using namespace std;

int main()
{
    int d, y, m;

    cin >> d;

    y = d / 365;

    d = d % 365;

    m = d / 30;

    d = d % 30;

    printf("%d years\n%d months\n%d days", y, m, d);

    return 0;
}