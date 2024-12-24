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
        int l = rand() % 1000;
        int r = l + rand() % 1000;
        int g = rand() % 1000;

        cout << l << " " << r << " " << g << "\n";
    }

    return 0;
}