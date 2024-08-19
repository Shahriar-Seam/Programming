#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long n, avg, count = 0;
    int i;

    cin >> n;

    vector <long long> v(n);

    for (auto &it : v) {
        cin >> it;
    }

    avg = accumulate(v.begin(), v.end(), 0LL) / n;

    sort(v.begin(), v.end());

    for (i = 0; i < n / 2; i++) {
        count += abs(avg - v[i]);
    }

    cout << count << "\n";

    return 0;
}