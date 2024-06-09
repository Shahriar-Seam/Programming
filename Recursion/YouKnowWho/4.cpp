#include <bits/stdc++.h>

using namespace std;

long long factorial(long long n)
{
    if (n == 1) {
        return 1;
    }
    else {
        return n * factorial(n - 1);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;

    cin >> n;

    cout << factorial(n);

    return 0;
}