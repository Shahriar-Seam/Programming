#include <bits/stdc++.h>

using namespace std;

#define sz 500005
#define mod int(1e8+7)
vector <int> fib(sz, 0);

void fibonacci()
{
    int i;

    fib[1] = fib[2] = 1;

    for (i = 3; i < sz; i++) {
        fib[i] = (fib[i - 1] + fib[i - 2]) % mod;
    }
}

void solve()
{
    int n;

    cin >> n;

    cout << fib[n] << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    fibonacci();

    int t;

    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}