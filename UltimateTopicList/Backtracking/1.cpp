#include <bits/stdc++.h>

using namespace std;

int total_count = 0, right_count = 0;
int n = 0, i, dest = 0, dora = 0;
string s1, s2;
int signs[12];

void permute(int index, int n)
{
    if (index == n) {
        int sum = 0;

        for (i = 0; i < n; i++) {
            sum += signs[i];
        }

        if (dora + sum == dest) {
            right_count++;
        }

        total_count++;

        return;
    }
    else {
        for (i = 0; i < n; i++) {
            
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> s1 >> s2;

    for (i = 0; i < s1.size(); i++) {
        dest += (s1[i] == '+' ? 1 : -1);

        if (s2[i] == '+') {
            dora++;
        }
        else if (s2[i] == '-') {
            dora--;
        }
        else {
            n++;
        }
    }

    permute(0, n);

    return 0;
}