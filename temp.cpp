#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int i, j;

    for (i = 0; i < 17; i++) {
        cout << (1 << i) << " = " << 1 << " ";

        for (j = 0; j < i; j++) {
            cout << "0 ";
        }

        cout << "\n";
    }

    return 0;
}