#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    srand(time(0));

    int t = rand() % 10;

    cout << t << "\n";

    for (int i = 0; i < t; i++) {
        int n = rand() % 10;
        int k = rand() % 20;
        string s;

        cout << n << " " << k << "\n";

        for (int j = 0; j < n; j++) {
            s += '0' + (rand() % 2);
        }

        cout << s << "\n";
    }

    return 0;
}