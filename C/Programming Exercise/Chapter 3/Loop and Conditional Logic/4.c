#include <stdio.h>

int main()
{
    int a, b, lcm;
    
    scanf("%d %d", &a, &b);

    if (a < b) {
        int temp = a;
        a = b;
        b = temp;
    }

    if (a % b == 0) {
        lcm = a;
    }
    else {
        for (int i = a; ; i += a) {
            if (i % b == 0) {
                lcm = i;
                break;
            }
        }
    }

    printf("LCM = %d\n", lcm);

    return 0;
}

// Check it out if you don't understand. You Donut.
// https://chat.openai.com/share/a92fb283-fd78-4768-a239-366734f21ce1