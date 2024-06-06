#include <bits/stdc++.h>

using namespace std;

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long n, i, s1 = 0, s2 = 0, s3 = 0, num;

    cin >> n;

    for (i = 0; i < n; i++) {
        cin >> num;

        s1 += num;
    }
    for (i = 0; i < n - 1; i++) {
        cin >> num;

        s2 += num;
    }
    for (i = 0; i < n - 2; i++) {
        cin >> num;

        s3 += num;
    }

    cout << s1 - s2 << "\n" << s2 - s3;

    return 0;
}
