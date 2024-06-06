#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, i, sum = 0;
    string num;

    cin >> n >> num;

    for (i = 0; i < n; i++) {
        sum += num[i] - '0';
    }

    cout << sum;

    return 0;
}