#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t, a, b, c, total;

    cin >> t;

    while (t--) {
        cin >> a >> b >> c;
        
        total = a + b + c;

        cout << ((total % 2) == (a % 2) ? "1 " : "0 ");
        cout << ((total % 2) == (b % 2) ? "1 " : "0 ");
        cout << ((total % 2) == (c % 2) ? "1\n" : "0\n");
    }
}
