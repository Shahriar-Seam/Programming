#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int a[3];

    cin >> a[0] >> a[1] >> a[2];

    sort(a, a + 3);

    cout << (a[0] * a[1] == a[2] ? "Yes" : "No");

    return 0;
}