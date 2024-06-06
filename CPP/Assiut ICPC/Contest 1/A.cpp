#include <bits/stdc++.h>

using namespace std;

int main()
{
    cout << fixed << setprecision(2);

    double x, p, t;

    cin >> x >> p;

    t = p / (1 - (x / 100));

    cout << t;

    return 0;
}