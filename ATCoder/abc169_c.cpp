#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cout << fixed << setprecision(20);

    long long a, b;
    double B;

    cin >> a >> B;

    b = 100 * (B + 1e-15);

    cout << (long long) ((a * b) / 100) << "\n";

    return 0;
}