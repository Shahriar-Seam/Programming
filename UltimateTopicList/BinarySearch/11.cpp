#include <bits/stdc++.h>

using namespace std;

long long n, k;
vector <long long> v;


bool possible(long long m)
{
    long long ops = 0;
    int i;

    for (i = n / 2; i < n; i++) {
        ops += max(0LL, m - v[i]);
    }

    return ops <= k;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long l = 0, r = 1e12, m;
    int i;

    cin >> n >> k;

    v.resize(n);

    for (auto &it : v) {
        cin >> it;
    }

    sort(v.begin(), v.end());

    for (i = 0; i < 60; i++) {
        m = l + (r - l) / 2;

        if (possible(m)) {
            l = m;
        }
        else {
            r = m;
        }
    }

    cout << l << "\n";

    return 0;
}