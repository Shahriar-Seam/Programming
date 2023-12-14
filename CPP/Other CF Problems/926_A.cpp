#include <bits/stdc++.h>

using namespace std;

long long power(long long n, long long p)
{
    long long i = 0, ans = 1;

    for (i = 0; i < p; i++) {
        ans *= n;
    }

    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long l, r, x, y, cnt, i, n;

    cnt = 0;

    cin >> l >> r;

    for (x = 0; x < 31; x++) {
        for (y = 0; y < 21; y++) {
            n = power(2, x) * power(3, y);

            if (n >= l && n <= r) {
                cnt++;
            }

            if (n > r) {
                break;
            }
        }
    }

    cout << cnt;

    return 0;
}