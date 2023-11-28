#include <bits/stdc++.h>

#define yes cout << "Yes\n"
#define no cout << "No\n"

using namespace std;

int main()
{
    int a, b, i, f = 1;
    string str;

    cin >> a >> b;
    cin >> str;

    for (i = 0; i < a; i++) {
        if (!isdigit(str[i])) {
            f = 0;
            break;
        }
    }

    for (i = a + 1; i < str.length(); i++) {
        if (!isdigit(str[i])) {
            f = 0;
            break;
        }
    }

    if (f == 0) {
        no;
    }
    else if (str[a] != '-') {
        no;
    }
    else if (str.length() != a + b + 1) {
        no;
    }
    else {
        yes;
    }

    return 0;
}