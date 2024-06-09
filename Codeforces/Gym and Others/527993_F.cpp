#include <bits/stdc++.h>

using namespace std;

void div7(int *n)
{
    while (*n > 7) {
        cout << 8;

        *n -= 7;
    }
}

void solve()
{
    int n;

    cin >> n;

    cout << n << " ";

    if (n % 7 == 0) {
        div7(&n);
    }
    else if (n > 7) {
        cout << 1;

        n -= 2;

        if (n % 7 == 0) {
            div7(&n);
        }
        else {
            while (n > 7) {
                cout << 0;

                n -= 6;

                if (n % 7 == 0) {
                    div7(&n);

                    break;
                }
            }
        }
    }

    if (n > 0) {
        switch (n)
        {
        case 2:
            cout << 1;
            break;
        case 3:
            cout << 7;
            break;
        case 4:
            cout << 4;
            break;
        case 5:
            cout << 2;
            break;
        case 6:
            cout << 0;
            break;
        case 7:
            cout << 8;
            break;

        default:
            break;
        }
    }

    cout << "\n";
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