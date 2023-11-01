#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long a, b, i, ab, ba;

    cin >> a >> b;
    
    ab = ba = 1;

    for (i = 0; i < b; i++) {
        ab *= a;
    }
    for (i = 0; i < a; i++) {
        ba *= b;
    }

    cout << ab - ba;

    return 0;
}