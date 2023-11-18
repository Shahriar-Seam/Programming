#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    string n;

    cin >> t;

    while (t--) {
        cin >> n;

        if (n.size() == 2) {
            cout << n[1] << "\n";
        }
        else {
            cout << *min_element(n.begin(), n.end()) << "\n";
        }
    }

    return 0;
}