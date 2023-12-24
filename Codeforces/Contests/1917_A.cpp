#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, i, neg = 0, pos = 0, temp, zero = 0;

    cin >> n;

    while (n--) {
        cin >> temp;

        if (temp == 0) {
            zero = 1;
        }
        else if (temp > 0) {
            pos++;
        }
        else {
            neg++;
        }
    }

    if (zero == 1) {
        cout << "0\n";
    }
    else if (neg % 2 == 1) {
        cout << "0\n";
    }
    else {
        cout << "1\n1 0\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;

    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}