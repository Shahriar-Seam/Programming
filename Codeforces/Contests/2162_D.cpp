#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, count = 0;
    int i, j, m, l, r;
    int a, b, c, d, len, mid, len_l, len_r;

    cin >> n;

    cout.flush();

    i = 1;
    j = n;

    cout << "1 1 " << n << endl;
    count++;

if (count >= 40) {
    goto print;
}
    cout.flush();
    cin >> a;
    cout.flush();

    cout << "2 1 " << n << endl;
    count++;

if (count >= 40) {
    goto print;
}
    cout.flush();
    cin >> b;
    cout.flush();

    len = b - a;

    while (i <= j) {
        m = (i + j) / 2;

        cout << 1 << " " << i << " " << m << endl;
        count++;

if (count >= 40) {
    goto print;
}

        cout.flush();

        cin >> a;

        cout.flush();

        cout << 2 << " " << i << " " << m << endl;
        count++;

if (count >= 40) {
    goto print;
}

        cout.flush();

        cin >> b;

        cout.flush();

        if (b == a) {
            i = m + 1;
        }
        else if (b - a == len) {
            j = m;

            if (m - i + 1 == len) {
                mid = m;

                len_l = b - a;
                len_r = len - len_l;

                l = i;

                break;
            }

            m = max(i + 1, (i + j) / 2);
        }
        else {
            mid = m;

            len_l = b - a;
            len_r = len - len_l;

            break;
        }

        cout << 1 << " " << m << " " << j << endl;
        count++;

if (count >= 40) {
    goto print;
}

        cout.flush();

        cin >> c;

        cout.flush();

        cout << 2 << " " << m << " " << j << endl;
        count++;

if (count >= 40) {
    goto print;
}

        cout.flush();

        cin >> d;

        cout.flush();

        if (d == c) {
            j = m - 1;
        }
        else if (d - c == len) {
            i = m;

            if (j - m + 1 == len) {
                mid = m;

                len_r = d - c;
                len_l = len - len_r;

                r = j;

                break;
            }
        }
        else {
            mid = m;

            len_r = d - c;
            len_l = len - len_r;

            break;
        }
    }

    i = 1;
    j = mid;

    if (len_l == 0) {
        l = mid;
    }
    else {
        while (i <= j) {
            m = (i + j) / 2;

            cout << 1 << " " << m << " " << mid << endl;
            count++;

if (count >= 40) {
    goto print;
}

            cout.flush();

            cin >> a;

            cout.flush();

            cout << 2 << " " << m << " " << mid << endl;
            count++;

if (count >= 40) {
    goto print;
}

            cout.flush();

            cin >> b;

            cout.flush();

            if (b - a == len_l) {
                l = m;

                if (mid - m + 1 == len_l) {
                    break;
                }
                else {
                    i = m + 1;
                }
            }
            else {
                j = m - 1;
            }
        }
    }

    i = mid;
    j = n;

    if (len_r == 0) {
        r = mid;
    }
    else {
        len_r++;

        while (i <= j) {
            m = (i + j) / 2;

            cout << 1 << " " << mid << " " << m << endl;
            count++;

if (count >= 40) {
    goto print;
}

            cout.flush();

            cin >> a;

            cout.flush();

            cout << 2 << " " << mid << " " << m << endl;
            count++;

if (count >= 40) {
    goto print;
}

            cout.flush();

            cin >> b;

            cout.flush();

            if (b - a == len_r) {
                r = m;

                if (m - mid == len_r) {
                    break;
                }
                else {
                    j = m - 1;
                }
            }
            else {
                i = m + 1;
            }
        }
    }

    print:

    cout.flush();

    cout << "! " << l << " " << r << endl;

    cout.flush();
}

int32_t main()
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);

    int32_t t, i;

    cout.flush();

    cin >> t;

    cout.flush();

    for (i = 1; i <= t; i++) {
        // cout << "Case " << i << ": ";

        solve();
    }

    return 0;
}