#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int a, b, c;

    cin >> a >> b;

    for (c = 0; c <= 255; c++) {
        if ((a ^ c) == b) {
            break;
        }
    }

    cout << c << "\n";

    return 0;
}