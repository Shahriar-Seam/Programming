#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long n, k, a, p;

    cin >> n >> k >> a;

    p = n * k / a;

    if ((n * k) % a == 0) {
        if (p <= 2147483647) {
            cout << "int";
        }
        else {
            cout << "long long";
        }
    }
    else {
        cout << "double";
    }

    return 0;
}