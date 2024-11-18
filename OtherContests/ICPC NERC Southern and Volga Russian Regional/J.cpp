#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    char op;
    int i;
    int total = 0;

    cin >> n;

    while (n--) {
        cin >> op >> i;

        if (op == 'P') {
            total += i;
        }
        else {
            if (total >= i) {
                cout << "NO\n";
            }
            else {
                cout << "YES\n";
            }

            total -= min(i, total);
        }
    }

    return 0;
}