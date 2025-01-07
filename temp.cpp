#include <bits/stdc++.h>

using namespace std;

#define int long long

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int i, sum = 0;

    for (i = 0; i < 100000000; i++) {
        sum += i;
    }

    cout << sum << "\n";

    return 0;
}