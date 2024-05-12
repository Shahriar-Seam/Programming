#include <bits/stdc++.h>

using namespace std;

set <long long> s;

void permute(int *arr, int l, int r)
{
    if (l == r) {
        long long num = 0;

        for (int i = 0; i < 10; i++) {
            num *= 10;
            num += arr[i];
        }

        s.insert(num);
    }
    else {
        for (int i = l; i <= r; i++) {
            swap(arr[l], arr[i]);

            permute(arr, l + 1, r);

            swap(arr[l], arr[i]);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int arr[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int i = 0;

    permute(arr, 0, 9);

    for (auto it : s) {
        i++;

        if (i == 1000000) {
            cout << it;
        }
    }

    return 0;
}