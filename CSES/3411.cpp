#include <bits/stdc++.h>
 
using namespace std;
 
#define int long long

void print(__int128_t n)
{
    vector <int> v;

    if (n == 0) {
        cout << 0 << "\n";
    }

    while (n > 0) {
        v.push_back(n % 10);

        n /= 10;
    }

    reverse(v.begin(), v.end());

    for (auto &it : v) {
        cout << it;
    }

    cout << "\n";
}
 
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    int n, i;
    __int128_t sum = 0;
 
    cin >> n;
 
    vector <int> x(n), y(n), pref_x(n + 1, 0), pref_y(n + 1, 0);
 
    for (i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
    }
 
    sort(x.begin(), x.end());
    sort(y.begin(), y.end());
 
    for (i = 0; i < n; i++) {
        pref_x[i + 1] = pref_x[i] + x[i];
        pref_y[i + 1] = pref_y[i] + y[i];
    }
 
    for (i = 0; i < n; i++) {
        sum += i * x[i] - pref_x[i];
        sum += i * y[i] - pref_y[i];
    }
 
    print(sum);
 
    return 0;
}