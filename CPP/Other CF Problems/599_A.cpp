#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int d1, d2, d3, m;

    cin >> d1 >> d2 >> d3;

    m = min({2 * (d1 + d2), d1 + d2 + d3, 2 * (d1 + d3), 2 * (d2 + d3)});

    cout << m;

    return 0;
}