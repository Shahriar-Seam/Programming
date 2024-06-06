#include <bits/stdc++.h>

using namespace std;

bool is_power_of_two (int x)
{
    return (x && !(x & (x - 1)));
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t, n;

    cin >> t;

    while (t--) {
        cin >> n;

        if (is_power_of_two(n)) {
            cout << "YES\n";
        }
        else {
            cout << "NO\n";
        }
    }

    return 0;
}