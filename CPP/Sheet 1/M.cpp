#include <bits/stdc++.h>

using namespace std;

int main()
{
    char ch;

    cin >> ch;

    if (isalpha((int) ch)) {
        cout << "ALPHA" << endl;

        if (isupper((int) ch)) {
            cout << "IS CAPITAL" << endl;
        }
        else {
            cout << "IS SMALL" << endl;
        }
    }
    else {
        cout << "IS DIGIT" << endl;
    }

    return 0;
}