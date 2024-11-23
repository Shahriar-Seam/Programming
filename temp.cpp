#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = i; j < n; j++)
            {
                int Max = arr[i];
                for (int k = i; k <= j; k++)
                {
                    if (arr[k] > Max)
                        Max = arr[k];
                }
                if (i == n - 1)
                {
                    cout << Max;
                }
                else
                {
                    cout << Max << " ";
                }
            }
        }
        cout << "\n";
    }
}