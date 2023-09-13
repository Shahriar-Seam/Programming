#include <stdio.h>

int main()
{
    int num, rev_num;

    scanf("%d", &num);

    while (num != 0) {
        rev_num = 0;
        while (num != 0) {
            rev_num = rev_num * 10;
            rev_num = rev_num + num % 10;
            num = num / 10;
        }

        printf("%d\n", rev_num);
        scanf("%d", &num);        
    }

    return 0;    
}

// How it works?
/* 
1st input, num = 123

num != 0

Enter secondary loop

initiate rev_num = 0

1st loop:
    rev_num = 0 * 10 = 0
    rev_num = 0 + 123 % 10 = 0 + 3 = 3
    num = 123 / 10 = 12
2nd loop:
    rev_num = 3 * 10 = 30
    rev_num = 30 + 12 % 10 = 30 + 2 = 32
    num = 12 / 10 =1
3rd loop:
    rev_num = 32 * 10 = 320
    rev_num = 320 + 1 % 10 = 320 + 1 = 321
    num = 1 / 10 =0
    break loop

rev_num = 321

next input ...
if input == 0 >> break primary loop
*/