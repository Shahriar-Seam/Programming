#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, i;
    set <int> s;

    cin >> n;

    for (i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            s.insert(i);
            s.insert(n / i);
        }
    }

    for (auto it : s) {
        cout << it << "\n";
    }

    return 0;
}