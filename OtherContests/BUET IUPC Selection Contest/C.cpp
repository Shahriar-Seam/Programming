#include <bits/stdc++.h>

using namespace std;

int possible(long long m, vector <long long> &a, vector <long long> &b, long long k, long long n)
{
    int i;

    for (i = 0; i < n; i++) {
        if (m * a[i] - b[i] > 0) {
            k -= m * a[i] - b[i];
        }

        if (k < 0) {
            return 0;
        }
    }

    return k >= 0;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long n, k;

    cin >> n >> k;

    vector <long long> a(n), b(n);

    for (auto &it : a) {
        cin >> it;
    }

    for (auto &it : b) {
        cin >> it;
    }

    long long r = 1e18, l = 0, m;

    for (int i = 0; i < 60; i++) {
        m = l + (r - l) / 2;

        if (possible(m, a, b, k, n)) {
            l = m;
        }
        else {
            r = m - 1;
        }
    }

    cout << l << "\n";

    return 0;
}