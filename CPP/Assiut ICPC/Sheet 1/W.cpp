#include <bits/stdc++.h>

#define plus a + b == c
#define minus a - b == c
#define multi a * b == c

#define yes cout << "Yes"

using namespace std;

int main()
{
    int a, b, c;
    char ch, eq;

    cin >> a >> ch >> b >> eq >> c;

    if (plus || minus || multi) {
        yes;
    }
    else {
        switch (ch) {
            case '+':
                cout << a + b;
                break;
                
            case '-':
                cout << a - b;
                break;
                
            case '*':
                cout << a * b;
                break;
        }
    }

    return 0;
}