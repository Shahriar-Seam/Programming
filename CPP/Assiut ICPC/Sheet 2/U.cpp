#include <bits/stdc++.h>

using namespace std;

int digit_sum(int n)
{
    int sum = 0;

    while (n != 0) {
        sum += n % 10;

        n /= 10;
    }

    return sum;
}

int main()
{
    int n, a, b, i, sum = 0;

    cin >> n >> a >> b;

    for (i = 1; i <= n; i++) {
        if (digit_sum(i) >= a && digit_sum(i) <= b) {
            sum += i;
        }
    }

    cout << sum;

    return 0;
}