#include <stdio.h>

int main()
{
    int n;

    printf("Enter a number from 1 to 6: ");
    scanf("%d", &n);

    if (n == 1) {
        printf(" CCCC\n");
        printf("CC\n");
        printf("C\n");
        printf("CC\n");
        printf(" CCCC\n");
    }

    else if (n == 2) {
        printf("    A      BBBB    CCCC  DDD    EEEEE\n");
        printf("   A A     B   B  CC     D  D   E\n");
        printf("  AAAAA    BBBB   C      D   D  EEE\n");
        printf(" A     A   B   B  CC     D  D   E\n");
        printf("A       A  BBBB    CCCC  DDD    EEEEE\n");
    }

    else if (n == 3) {
        printf(" 11      +    2222          3333\n");
        printf("  1      +        2  =====      3\n");
        printf("  1    +++++    22   =====    33\n");
        printf("  1      +    22                3\n");
        printf("11111    +    2222          3333\n");
    }

    else if (n == 4) {
         printf("    #\n");
         printf("   ##\n");
         printf("  ###\n");
         printf(" ####\n");
         printf("#####\n");
    }

    else if (n == 5) {
        printf("#\n");
        printf("##\n");
        printf("###\n");
        printf("####\n");
        printf("#####\n");
    }

    else if (n == 6) {
        printf("#\n");
        printf(" #\n");
        printf("  #\n");
        printf("   #\n");
        printf("    #\n");
    }

    else {
        printf("EEEEE  RRR    RRR     OOO    RRR\n");
        printf("E      R  R   R  R   O   O   R  R\n");
        printf("EEE    RRR    RRR   O     O  RRR\n");
        printf("E      R  R   R  R   O   O   R  R\n");
        printf("EEEEE  R   R  R   R   OOO    R   R\n");
    }
    
}