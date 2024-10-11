#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int high, low = 1, k;
    string s;

    cin >> high;

    while (1) {
        k = low + (high - low) / 2;

        cout << "guess " << k << "\n";

        cin >> s;

        if (s == "correct" || s == "too many tries") {
            break;
        }
        else if (s == "low") {
            low = k + 1;
        }
        else {
            high = k - 1;
        }
    }

    return 0;
}