#include <bits/stdc++.h>

using namespace std;

void possible(int nums[], int result, int index, int &f)
{
    if (index == 5) {
        if (result == 23) {
            f = 1;
        }

        return;
    }

    possible(nums, result + nums[index], index + 1, f);
    possible(nums, result - nums[index], index + 1, f);
    possible(nums, result * nums[index], index + 1, f);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    while (true) {
        int nums[5], f = 0;

        cin >> nums[0] >> nums[1] >> nums[2] >> nums[3] >> nums[4];

        if (accumulate(nums, nums + 5, 0) == 0) {
            break;
        }

        sort(nums, nums + 5);

        do {
            possible(nums, nums[0], 1, f);
        } while (next_permutation(nums, nums + 5));


        cout << (f ? "Possible" : "Impossible") << "\n";
    }

    return 0;
}