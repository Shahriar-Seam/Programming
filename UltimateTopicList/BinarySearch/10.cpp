#include <bits/stdc++.h>

using namespace std;

double c;

bool possible(double x)
{
    return x * x + sqrt(x) >= c;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout << setprecision(20);

    double l, r, x;
    int i;

    cin >> c;

    for (i = 0, l = 0, r = c + 5; i < 100; i++) {
        x = l + (r - l) / 2;

        if (possible(x)) {
            r = x;
        }
        else {
            l = x;
        }
    }

    cout << r << "\n";

    return 0;
}