#include <iostream>

using namespace std;

int main()
{
    int t, a, b;

    cin >> t;

    while (t--) {
        cin >> a >> b;

        (a == b) ? cout << "Square\n" : cout << "Rectangle\n";
    }

    return 0;
}