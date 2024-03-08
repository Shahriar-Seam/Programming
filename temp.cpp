#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int a, b;

    for (a = 3; a < 5000; a++) {
        for (b = 0; b < 5000; b++) {
            if (a * (b + 2008) == (a - 2) * (b + 2021)) {
                cout << a << " " << b << endl;
            }
        }
    }

    return 0;
}