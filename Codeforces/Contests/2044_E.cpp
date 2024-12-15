#include <bits/stdc++.h>

using namespace std;

#define int long long

int first(int l1, int r1, int l2, int r2, int k)
{
    int mid, f = -1;

    while (l1 <= r1) {
        mid = (l1 + r1) / 2;

        if (l2 <= mid * k && mid * k <= r2) {
            f = mid * k;

            r1 = mid - 1;
        }
        else if (mid * k > r2) {
            r1 = mid - 1;
        }
        else if (mid * k < l2) {
            l1 = mid + 1;
        }
    }

    return f;
}

int last(int l1, int r1, int l2, int r2, int k)
{
    int mid, l = -1;

    while (l1 <= r1) {
        mid = (l1 + r1) / 2;

        if (l2 <= mid * k && mid * k <= r2) {
            l = mid * k;

            l1 = mid + 1;
        }
        else if (mid * k > r2) {
            r1 = mid - 1;
        }
        else if (mid * k < l2) {
            l1 = mid + 1;
        }
    }

    return l;
}

int binary_exponentiation(int b, int p)
{
    int result = 1;

    while (p > 0) {
        if (p & 1LL) {
            result = result * b;
        }

        b = b * b;

        p >>= 1LL;
    }

    return result;
}

void solve()
{
    int k, l1, l2, r1, r2;
    int x, y, n, num, f, l, count = 0;

    cin >> k >> l1 >> r1 >> l2 >> r2;

    for (n = 0; ; n++) {
        num = binary_exponentiation(k, n);

        if (num > r2) {
            break;
        }

        f = first(l1, r1, l2, r2, num);
        l = last(l1, r1, l2, r2, num);

        if (f >= 0 && l >= 0) {
            count += (l - f) / num + 1;
        }
    }

    cout << count << "\n";
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;

    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}