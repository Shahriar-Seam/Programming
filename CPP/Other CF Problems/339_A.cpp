#include <bits/stdc++.h>

using namespace std;

int main()
{
    string str;
    int *arr;
    int len, one = 0, two = 0, three = 0, cnt, i;

    cin >> str;

    len = str.length();

    one = count(str.begin(), str.end(), '1');
    two = count(str.begin(), str.end(), '2');
    three = count(str.begin(), str.end(), '3');

    cnt = one + two + three;
    arr = (int *) calloc(cnt, sizeof(int));

    for (i = 0; i < one; i++) {
        arr[i] = 1;
    }
    for (i; i < one + two; i++) {
        arr[i] = 2;
    }
    for (i; i < cnt; i++) {
        arr[i] = 3;
    }

    for (i = 0; i < cnt; i++) {
        cout << arr[i];
        if (i != cnt - 1) {
            cout << "+";
        }
    }

    return 0;
}