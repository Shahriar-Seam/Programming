#include <bits/stdc++.h>

using namespace std;

int main()
{
    string str;
    long long sum = 0, len, i;

    cin >> str;

    len = str.length();

    for (i = 0; i < len; i++) {
        sum += str[i] - '0';
    }

    cout << sum;

    return 0;
}