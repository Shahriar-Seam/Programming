#include <bits/stdc++.h>

using namespace std;

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    srand(time(0));

    int n = 10000;

    for (int i = 0; i < n; i++) {
        cout << char('a' + (rand() % 26));
    }

    return 0;
}