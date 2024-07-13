#include <bits/stdc++.h>

using namespace std;

int used[20], number[20];

void permute(int index, int n)
{
    if (index == n) {
        for (int i = 0; i < n; i++) {
            cout << number[i] << " ";
        }

        cout << "\n";

        return;
    }
    else {
        for (int i = 0; i < n; i++) {
            if (!used[i]) {
                used[i] = 1;

                number[index] = i + 1;

                permute(index + 1, n);

                used[i] = 0;
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;

    cin >> n;

    permute(0, n);

    return 0;
}