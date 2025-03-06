#include <bits/stdc++.h>

using namespace std;

void solve(vector <string> &board, int row, vector <bool> &occupied_column, vector <bool> &occupied_primary, vector <bool> &occupied_secondary, int &num_ways)
{
    if (row == 8) {
        num_ways++;

        return;
    }

    int col;

    for (col = 0; col < 8; col++) {
        if (board[row][col] == '*' || occupied_column[col] || occupied_primary[row - col + 8] || occupied_secondary[row + col]) {
            continue;
        }

        occupied_column[col] = occupied_primary[row - col + 8] = occupied_secondary[row + col] = true;

        solve(board, row + 1, occupied_column, occupied_primary, occupied_secondary, num_ways);

        occupied_column[col] = occupied_primary[row - col + 8] = occupied_secondary[row + col] = false;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector <string> board(8);
    vector <bool> occupied_column(10, false), occupied_primary(20, false), occupied_secondary(20, false);
    int num_ways = 0;

    for (auto &it : board) {
        cin >> it;
    }

    solve(board, 0, occupied_column, occupied_primary, occupied_secondary, num_ways);

    cout << num_ways << "\n";

    return 0;
}