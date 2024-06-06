#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int i;

    for (i = 1; i <= 100; i++) {
        if (!(i % 3) && !(i % 5)) {
            cout << "FizzBuzz\n";
        }
        else if (!(i % 3)) {
            cout << "Fizz\n";
        }
        else if (!(i % 5)) {
            cout << "Buzz\n";
        }
        else {
            cout << i << "\n";
        }
    }

    return 0;
}