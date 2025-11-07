#include <bits/stdc++.h>

using namespace std;

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, i, j, count, cnt;

    cin >> n >> m;

    vector <int> a(n), b(m), temp;

    for (auto &it : a) {
        cin >> it;
    }

    for (auto &it : b) {
        cin >> it;
    }

    temp = a;

    sort(b.begin(), b.end(), greater <> ());

    for (i = n - 2, j = 0, cnt = 0; i >= 0; i--) {
        if (a[i] > a[i + 1]) {
            while (j < m && b[j] > a[i + 1]) {
                j++;
            }

            if (j < m) {
                a[i] = b[j++];

                cnt++;
            }
            else {
                break;
            }
        }
    }

    if (is_sorted(a.begin(), a.end())) {
        count = cnt;
    }
    else {
        count = -1;
    }

    a = temp;

    if (a.back() < b[0]) {
        a[n - 1] = b[0];

        for (i = n - 2, j = 1, cnt = 1; i >= 0; i--) {
            if (a[i] > a[i + 1]) {
                while (j < m && b[j] > a[i + 1]) {
                    j++;
                }

                if (j < m) {
                    a[i] = b[j++];

                    cnt++;
                }
                else {
                    break;
                }
            }
        }

        if (is_sorted(a.begin(), a.end())) {
            if (count == -1) {
                count = cnt;
            }
            else {
                count = min(count, cnt);
            }
        }
        else {
            count = -1;
        }
    }

    cout << count << "\n";

    return 0;
}