#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int b, g, ways = 0;

    cin >> b >> g;
    
    if (g >= 3) {
        ways = (g * (g - 1) * (g - 2) / 6) * 6;
    }
    
    if (g >= 2 && b >= 1) {
        ways += ((g * (g - 1) / 2) * b) * 6;
    }
    
    cout << ways << "\n";

    return 0;
}