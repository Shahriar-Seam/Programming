#include <bits/stdc++.h>

using namespace std;

long long n, k;
vector <long long> v;

bool possible(long long m)
{
    long long sub_array_count = 1, sum = 0;

    for (auto it : v) {
        if (it > m) {
            return false;
        }

        if (sum + it > m) {
            sub_array_count++;
            sum = it;
        }
        else {
            sum += it;
        }
    }

    return sub_array_count <= k;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long l = 0, r = 1e16, m;
    int i;

    cin >> n >> k;

    v.resize(n);

    for (auto &it : v) {
        cin >> it;
    }

    for (i = 0; i < 70; i++) {
        m = l + (r - l) / 2;

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