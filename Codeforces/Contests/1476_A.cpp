#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t, n, k;

    cin >> t;

    while (t--) {
        cin >> n >> k;

        cout << ceil((double) max({k, n}) / min({k, n})) << "\n";
    }

    return 0;
}