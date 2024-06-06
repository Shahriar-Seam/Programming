#include <stdio.h>

int main()
{
    int n, n_dec, n_bin = 0, r, i = 1;

    scanf("%d", &n_dec);
    n = n_dec;

    while (n_dec != 0) {
        r = n_dec % 2;
        n_bin = n_bin + r * i;
        i *= 10;
        n_dec = n_dec / 2;
    }

    if (n != 0) {
        printf("The binary of %d is: %d\n", n, n_bin);
    }
    else {
        printf("The binary of %d is: %d\n", 0, 0);
    }
    
    return 0;
}

// Explanation of the loop by ChatGPT.

// The code you provided appears to be a loop that converts a decimal number (`n_dec`) into its binary representation (`n_bin`). Here's a breakdown of how the code works:

// 1. Initialize variables:
//    - `n_dec`: The decimal number to be converted.
//    - `n_bin`: The binary representation of `n_dec`, initially set to 0.
//    - `r`: The remainder when `n_dec` is divided by 2 (the current bit in binary representation).
//    - `i`: A multiplier used to calculate the position of the current bit.

// 2. Enter the loop:
//    - The loop continues as long as `n_dec` is not equal to 0.

// 3. Calculate the remainder and update `n_bin`:
//    - `r = n_dec % 2` calculates the remainder when `n_dec` is divided by 2.
//    - `n_bin = n_bin + r * i` updates `n_bin` by adding the current bit (`r`) multiplied by `i`.
//      - Multiplying `r` by `i` sets the value of the current bit at the corresponding position.
//      - For example, if `r` is 1 and `i` is 10, the bit at position 1 is set to 1.
//    - This step accumulates the binary representation of `n_dec` bit by bit.

// 4. Update `i` and `n_dec` for the next iteration:
//    - `i *= 10` updates the multiplier `i` by multiplying it by 10.
//      - This effectively shifts the position of the next bit to the left by one place.
//    - `n_dec = n_dec / 2` updates `n_dec` by dividing it by 2.
//      - This discards the least significant bit, preparing for the next iteration.

// 5. Repeat the loop until `n_dec` becomes 0:
//    - The loop continues until `n_dec` is equal to 0.
//    - With each iteration, the next bit of the binary representation is calculated and added to `n_bin`.

// After the loop completes, the variable `n_bin` will contain the binary representation of the initial decimal number `n_dec`.