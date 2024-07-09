#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector <int> colors = {0, 1, 0, 1, 0};

    for (int i = 0; i < k; i++) {
        colors.push_back(colors[i]);
    }

    int n = colors.size();
    int cnt = 0;

    for (int i = 1; i < n - 1; i++) {
        if (colors[i - 1] == colors[i + 1] && colors[i] != colors[i - 1]) {
            cnt++;
        }
    }

    cout << cnt;

    return 0;
}