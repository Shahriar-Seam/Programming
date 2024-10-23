#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        int p, sum = 0;
        cin >> p;
        int A[p + 1];
        for (int i = 1; i <= p + 1; i++)
        {
            cin >> A[i];
            if (A[i] < 2 * A[p + 1])
            {
                int temp = A[i];
                A[i] = A[p + 1];
                A[p + 1] = temp;
                break;
                for (int j = 0; j <= p; j++)
                {
                    sum += A[i];
                }
            }
            else if (A[i] > 2 * A[p + 1])
            {
                for (int j = 0; j <= p; j++)
                {
                    sum += A[i];
                }
            }
            cout << sum << "\n";
        }
    }

    return 0;
}