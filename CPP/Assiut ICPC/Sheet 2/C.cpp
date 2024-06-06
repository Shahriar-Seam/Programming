#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t, i, num, e = 0, o = 0, p = 0, n = 0;

    cin >> t;

    for (i = 0; i < t; i++) {
        cin >> num;

        if (num > 0) { p++; }
        else if (num < 0) { n++; }

        if (num % 2 == 0) { e++; }
        else { o++; }
    }

    cout << "Even: " << e << "\n";
    cout << "Odd: " << o << "\n";
    cout << "Positive: " << p << "\n";
    cout << "Negative: " << n << "\n";

    return 0;
}