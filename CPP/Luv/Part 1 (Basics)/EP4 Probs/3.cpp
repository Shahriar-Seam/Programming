#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t, n, sum;

    cin >> t;

    while (t--) {
        cin >> n;

        sum = 0;

        while (n != 0) {
            sum += n % 10;
            n /= 10;
        }

        cout << sum << endl;
    }

    return 0;
}