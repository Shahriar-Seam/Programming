#include <bits/stdc++.h>

using namespace std;

int main()
{
    char s;
    int n, *num, i, j;

    cin >> s;
    cin >> n;

    num = (int *) malloc(sizeof(int) * n);

    for (i = 0; i < n; i++) {
        cin >> num[i];
    }

    for (i = 0; i < n; i++) {
        for (j = 0; j < num[i]; j++) {
            cout << s;
        }

        cout << "\n";
    }

    return 0;
}