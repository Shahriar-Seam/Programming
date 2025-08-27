#include <bits/stdc++.h>
 
using namespace std;
 
#define int long long
 
int ceil_div(int a, int b)
{
    return (a + b - 1) / b;
}
 
int pow10(int p)
{
    int n = 1;
 
    while (p--) {
        n *= 10;
    }
 
    return n;
}
 
void solve()
{
    int k, i = 1, c = 9, n;
 
    cin >> k;
 
    while (k > i * c) {
        k -= i * c;
 
        i++;
 
        c *= 10;
    }
 
    n = pow10(i - 1) - 1;
 
    cout << to_string(n + ceil_div(k, i)).at((k % i) == 0 ? i - 1 : (k % i) - 1) << "\n";
}
 
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    int32_t t, i;
 
    cin >> t;
 
    for (i = 1; i <= t; i++) {
        // cout << "Case " << i << ": ";
 
        solve();
    }
 
    return 0;
}