#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, i;
    vector <int> v;

    cin >> n;

    if (n == 0) {
        cout << 10;
    }
    else if (n < 10) {
        cout << n;
    }
    else {
        for (i = 9; i >= 2; i--) {
            while (n % i == 0) {
                v.push_back(i);

                n /= i;
            }
        }

        if (n != 1) {
            cout << -1;
        }
        else {
            for (auto it = v.rbegin(); it != v.rend(); it++) {
                cout << *it;
            }
        }
    }

    return 0;
}