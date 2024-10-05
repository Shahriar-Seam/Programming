#include <bits/stdc++.h>
 
using namespace std;
 
long long n, k;
 
bool possible(long long m)
{
    long long cnt = 0, i;
 
    for (i = 1; i <= n; i++) {
        cnt += min(n, m / i);
    }
 
    return cnt >= k;
}
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    cin >> n >> k;
 
    long long l = 1, r = n * n, m, i;
 
    for (i = 0; i < 60; i++) {
        m = l + (r - l) / 2;
 
        if (possible(m)) {
            r = m;
        }
        else {
            l = m + 1;
        }
    }
 
    cout << r << "\n";
 
    return 0;
}
