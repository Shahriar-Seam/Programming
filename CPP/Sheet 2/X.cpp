#include <bits/stdc++.h>

using namespace std;

void solve();

int main()
{
    int t;

    cin >> t;

    while (t--) {
        solve();
    }
}

void solve()
{
    int n, c;
    char bin[32];
    int dec = 0;

    cin >> n;

    itoa(n, bin, 2);

    c = count(bin, bin + strlen(bin), '1');

    char bin2[c + 1];
    memset(bin2, '1', c);

    for (int i = 0; i < c; i++) {
        dec += 1 << i;
    }

    cout << dec << "\n";
}