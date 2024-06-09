#include <bits/stdc++.h>

using namespace std;

void recurse(int n, int count)
{
    if (count == n) {
        return;
    }
    else {
        cout << "I love Recursion\n";

        recurse(n, count + 1);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;

    cin >> n;

    recurse(n, 0);

    return 0;
}