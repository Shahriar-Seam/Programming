#include <stdio.h>

int main()
{
    int num, rev_num = 0;

    scanf("%d", &num);

    while (num != 0) {
        int remainder = num % 10;
        rev_num = rev_num * 10 + remainder;
        num /= 10;
    }

    /* Let, num = 123.

    1st loop:
        remainder = 123 % 10 = 3.
        rev_num = 0 * 10 + 3 = 3.
        num = 123 / 10 = 12.
    2nd loop:
        remainder = 12 % 10 = 2.
        rev_num = 3 * 10 + 2 = 32.
        num = 12 / 10 = 1.
    3rd loop:
        remainder = 1 % 10 = 1.
        rev_num = 32 * 10 + 1 = 321.
        num = 1 / 10 = 0 [Loop break.]

    The reversed number is {rev_num}: 321. 
    */

    printf("%d\n", rev_num);

    return 0;
}