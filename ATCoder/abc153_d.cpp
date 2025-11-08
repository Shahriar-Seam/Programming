#include <bits/stdc++.h>

using namespace std;

#define int long long

int f(int h)
{
    if (h == 1) {
        return 1;
    }
    else {
        return f(h / 2) * 2 + 1;
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int h;

    cin >> h;

    cout << f(h) << "\n";

    return 0;
}