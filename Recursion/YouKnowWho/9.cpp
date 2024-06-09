#include <bits/stdc++.h>

using namespace std;

int is_palindrome(vector <int> &v, int i, int n)
{
    if (i == n) {
        return 1;
    }
    else {
        return (v[i] == v[n - i - 1]) && is_palindrome(v, i + 1, n);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;

    cin >> n;

    vector <int> v(n);

    for (auto &it : v) {
        cin >> it;
    }

    cout << (is_palindrome(v, 0, n) == 1 ? "YES" : "NO");

    return 0;
}