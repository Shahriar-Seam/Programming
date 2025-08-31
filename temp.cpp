#include <bits/stdc++.h>

using namespace std;

int sum_of_digits(int x)
{
    int s = 0;

    while (x != 0) {
        s += x % 10;
        x /= 10;
    }

    return s;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t, s = 0, j;

    cin >> t;

    for (j = 1; j <= t; j++) {
        s += sum_of_digits(j);
    }

    cout << "Sum of digits from 1 to " << t << " is: " << s << endl;

    return 0;
}