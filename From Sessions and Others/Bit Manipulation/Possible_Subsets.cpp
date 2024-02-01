#include <bits/stdc++.h>

using namespace std;

void possible_subsets (char *s, int n)
{
    int i, j;

    for (i = 0; i < (1 << n); i++) {
        for (j = 0; j < n; j++) {
            if (i & (1 << j)) {
                cout << (1 << j) << " " << s[j] << " ";
            }
        }

        cout << endl;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    char s[] = "abc";

    possible_subsets(s, 3);

    return 0;
}