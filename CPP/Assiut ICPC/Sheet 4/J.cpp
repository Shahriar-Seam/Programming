#include <bits/stdc++.h>

using namespace std;

int main()
{
    string s;
    int i, len, arr[128] = {0};

    cin >> s;

    len = s.length();

    for (i = 0; i < len; i++) {
        arr[s[i]]++;
    }

    for (i = 97; i < 128; i++) {
        if (arr[i] != 0) {
            printf("%c : %d\n", i, arr[i]);
        }
    }

    return 0;
}