#include <bits/stdc++.h>

using namespace std;

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int a, b;

    cin >> a >> b;

    cout << (abs(a - b) == 1 || abs(a - b) == 9 ? "Yes" : "No") << "\n";

    return 0;
}