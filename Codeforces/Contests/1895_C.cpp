#include <bits/stdc++.h>

using namespace std;

int is_lucky(string s, int len)
{
    int i, sum1 = 0, sum2 = 0;

    if (len % 2 == 1) {
        return 0;
    }

    for (i = 0; i < len / 2; i++) {
        sum1 += s[i] - '0';
    }
    
    for (i = len / 2; i < len; i++) {
        sum2 += s[i] - '0';
    }

    return (sum1 == sum2) ? 1 : 0;
}

int main()
{
    int n, i, j, cnt = 0, *arr;

    cin >> n;

    arr = new int[n]();
    string s[n];
    string temp;

    for (i = 0; i < n; i++) {
        cin >> s[i];

        arr[i] = s[i].length();
    }

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            temp = s[i] + s[j];

            if (is_lucky(temp, arr[i] + arr[j])) {
                cnt++;
            }
        }
    }

    cout << cnt;

    return 0;
}