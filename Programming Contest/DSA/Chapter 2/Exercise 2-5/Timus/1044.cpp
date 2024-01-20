#include <bits/stdc++.h>

using namespace std;

bool is_lucky(int n, int mod)
{
    int i, temp1, temp2, sum1 = 0, sum2 = 0;

    temp1 = n / mod;
    temp2 = n % mod;

    while (temp1 > 0 || temp2 > 0) {
        sum1 += temp1 % 10;
        sum2 += temp2 % 10;

        temp1 /= 10;
        temp2 /= 10;
    }

    if (sum1 == sum2) {
        return true;
    }
    else {
        return false;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, i, num = 10, cnt = 0, mod = 1;

    cin >> n;

    for (i = 1; i < n; i++) {
        num *= 10;

        if (i <= ceil(n / 2.0)) {
            mod *= 10;
        }
    }

    for (i = 0; i < num; i++) {
        if (is_lucky(i, mod)) {
            cnt++;
        }
    }

    cout << cnt;

    return 0;
}