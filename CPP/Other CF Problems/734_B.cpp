#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long a, b, c, d, sum;

    cin >> a >> b >> c >> d;

    sum = min({a, c, d}) * 256;

    a -= min({a, c, d});

    sum += min({a, b}) * 32;

    cout << sum;

    return 0;
}