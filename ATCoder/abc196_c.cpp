#include <bits/stdc++.h>

using namespace std;

#define int long long

int num_ints(int n)
{
    int i;

    for (i = 1; i < n; i++) {
        if (stoll(to_string(i) + to_string(i)) > n) {
            return i - 1;
        }
    }

    return 0;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;

    cin >> n;

    cout << num_ints(n) << "\n";

    return 0;
}