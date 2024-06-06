#include <stdio.h>
#include <string.h>

int main()
{
    char str[102];

    scanf("%s", str);

    int i, len = strlen(str), count = 0;

    for (i = 0; i < len; i++) {
        if (str[i] == 'h') {
            count++;
            // printf("count1 = %d\n", count);

            for (int j = i + 1; j < len; j++) {
                if (str[j] == 'e') {
                    count++;
                    // printf("count2 = %d\n", count);

                    for (int k = j + 1; k < len; k++) {
                        if (str[k] == 'l') {
                            count++;
                            // printf("count3 = %d\n", count);

                            for (int l = k + 1; l < len; l++) {
                                if (str[l] == 'l') {
                                    count++;
                                    // printf("count4 = %d\n", count);

                                    for (int m = l + 1; m < len; m++) {
                                        if (str[m] == 'o') {
                                            count++;
                                            // printf("count5 = %d\n", count);

                                            break;
                                        }
                                    }

                                    break;
                                }
                            }

                            break;
                        }
                    }

                    break;
                }
            }

            break;
        }
    }

    // printf("count = %d\n", count);
    
    (count == 5) ? (printf("YES")) : (printf("NO")) ;

    return 0;
}