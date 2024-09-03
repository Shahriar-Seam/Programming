#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int r, c, sum_1 = 0, sum_2 = 0, count_1 = 0, count_2 = 0;

    cin >> r >> c;

    int arr[r][c];

    // Input
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> arr[i][j];
        }
    }

    // Left & Right column
    for (int i = 0; i < r; i++) {
        sum_1 += arr[i][0] + arr[i][c - 1];
        count_1++;
    }

    // Top & Bottom Row
    // Last column elements are not taken as 
    // they have already been added in the previous loop
    for (int j = 1; j < c - 1; j++) {
        sum_1 += arr[0][j] + arr[r - 1][j];
        count_1++;
    }

    // Nested loop
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (i == 0 || j == 0 || i == r - 1 || j == c - 1) {
                sum_2 += arr[i][j];
            }

            count_2++;
        }
    }

    cout << "Non Nested:\n\tSum = " << sum_1 << ", Iterations: " << count_1 << "\n";
    cout << "Nested:\n\tSum = " << sum_2 << ", Iterations: " << count_2 << "\n";

    // Complexity
    // O(r + c) and O(r * c)

    return 0;
}