#include <bits/stdc++.h>

using namespace std;

int main()
{
    char ch;

    cin >> ch;

    if (isupper(ch)) {
        cout << (char) tolower(ch);
    }
    else {
        cout << (char) toupper(ch);
    }

    return 0;
}