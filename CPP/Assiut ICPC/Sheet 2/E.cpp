#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t, n, m = 0;

    cin >> t;

    while (t--) {
        cin >> n;

        m = (n > m) ? n : m;
    }

    cout << m;

    return 0;
}