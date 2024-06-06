#include <bits/stdc++.h>

#define yes cout << "YES"
#define no cout << "NO"

using namespace std;

int main()
{
    long long a, b, c, d;

    cin >> a >> b >> c >> d;

    if (a + b - c == d) {
        yes;
    }
    else if (a + b * c == d) {
        yes;
    }
    else if (a - b + c == d) {
        yes;
    }
    else if (a - b * c == d) {
        yes;
    }
    else if (a * b + c == d) {
        yes;
    }
    else if (a * b - c == d) {
        yes;
    }
    else {
        no;
    }

    return 0;
}