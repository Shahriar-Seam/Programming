#include <bits/stdc++.h>

using namespace std;

int main()
{
    string str1, str2;

    cin >> str1;
    cin >> str2;

    if (str1 < str2) {
        cout << str1;
    }
    else {
        cout << str2;
    }

    return 0;
}