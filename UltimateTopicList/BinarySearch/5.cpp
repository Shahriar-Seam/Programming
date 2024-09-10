#include <bits/stdc++.h>

using namespace std;

long long n, t;
vector <long long> v;

bool possible(unsigned long long m)
{
    unsigned long long cnt = 0;

    for (auto it : v) {
        cnt += (1ULL * m) / it;
    }

    return cnt >= t;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int i;
    unsigned long long l, r, m;

    cin >> n >> t;

    v.resize(n);

    for (auto &it : v) {
        cin >> it;
    }

    for (i = 0, l = 0, r = *max_element(v.begin(), v.end()) * t + 5; i < 100; i++) {
        m = (r + l) / 2;

        if (possible(m)) {
            r = m;
        }
        else {
            l = m;
        }
    }

    cout << r << "\n";

    return 0;
}