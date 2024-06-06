#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, m, i, sum;

    while (1) {
        cin >> n >> m;

        sum = 0;

        if (n <= 0 || m <= 0) {
            return 0;
        }
        else {
            for (i = min(m, n); i <= max(m, n); i++) {
                cout << i << " ";

                sum += i;
            }

            cout << "sum =" << sum << "\n";
        }
    }

    return 0;
}