#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    srand(time(0));

    int t = 200;

    cout << t << "\n";

    for (int i = 0; i < t; i++) {
        int n = 50;

        cout << n << "\n";

        for (int j = 0; j < n; j++) {
            cout << pow(-1, rand() % 2) * (rand() % 1001) << " ";
        }

        cout << "\n";
    }

    return 0;
}