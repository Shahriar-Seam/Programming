#include <bits/stdc++.h>

using namespace std;

int main()
{
    cout << fixed << setprecision(3);
    
    float n;

    cin >> n;

    if (n - (int) n == 0) {
        cout << "int " << (int) n;
    }
    else {
        cout << "float " << (int) n << " " << n - (int) n;
    }

    return 0;
}