#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, rev;
    string str;

    cin >> n;

    str = to_string(n);

    reverse(str.begin(), str.end());

    rev = stoi(str);

    cout << rev << "\n";

    (n == rev) ? cout << "YES" : cout << "NO";

    return 0;
}