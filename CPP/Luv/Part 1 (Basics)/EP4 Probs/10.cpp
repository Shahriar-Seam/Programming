#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;

    cin >> n;

    if (n % 4 == 0 || n % 4 == 3) {
        cout << 0;
    }
    else {
        cout << 1;
    }

    return 0;
}