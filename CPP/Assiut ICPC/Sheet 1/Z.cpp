#include <bits/stdc++.h>

using namespace std;

int main()
{
    double a, b, c, d, lna, lnc;

    cin >> a >> b >> c >> d;

    lna = b * log(a);
    lnc = d * log(c);

    if (lna > lnc) {
        cout << "YES" << endl;
    }
    else {
        cout << "NO" << endl;
    }

    return 0;
}