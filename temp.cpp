#include <bits/stdc++.h>

using namespace std;

int bla(int a)
{
    return 5 * a;
}

int bla(int a, int b)
{
    return b * 2;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cout << bla(5) << " " << bla(5, 2);

    return 0;
}