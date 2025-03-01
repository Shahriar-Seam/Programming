#include <bits/stdc++.h>

using namespace std;

void sort(int &a, int &b, int &c)
{
    if (a > b) {
        swap(a, b);
    }

    if (b > c) {
        swap(b, c);
    }

    if (a > b) {
        swap(a, b);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int a, b, c;

    cin >> a >> b >> c;

    sort(a, b, c);

    cout << (a * b == c ? "Yes" : "No") << "\n";

    return 0;
}