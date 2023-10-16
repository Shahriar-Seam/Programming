#include <bits/stdc++.h>

using namespace std;

int main()
{
    int x, f;

    cin >> x;
    
    f = x / 1000;

    if ((f & 1) == 0) {
        cout << "EVEN";
    }
    else {
        cout << "ODD";
    }

    return 0;
}