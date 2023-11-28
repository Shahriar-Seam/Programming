#include <bits/stdc++.h>

#define right cout << "Right"
#define wrong cout << "Wrong"

using namespace std;

int main()
{
    int a, b;
    char c;

    cin >> a >> c >> b;

    if (c == '>' && a > b) {
        right;
    }
    else if (c == '=' && a == b) {
        right;
    }
    else if (c == '<' && a < b) {
        right;
    }
    else {
        wrong;
    }

    return 0;
}