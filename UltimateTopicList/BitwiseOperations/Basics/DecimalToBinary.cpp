#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, i;

    cin >> n;

    for (i = log2(n); i >= 0; i--) {
        if (n & (1 << i)) {
            cout << 1;
        }
        else {
            cout << 0;
        }
    }

    return 0;
}