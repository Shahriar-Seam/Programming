#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long n, x, ic, count;
    char ch;

    cin >> n >> x;

    while (n--) {
        cin >> ch >> ic;

        if (ch == '+') {
            x += ic;
        }
        else {
            if (ic > x) {
                count++;
            }
            else {
                x -= ic;
            }
        }
    }

    cout << x << " " << count;

    return 0;
}