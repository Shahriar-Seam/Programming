#include <stdio.h>

int main()
{
    float m, cm, f, in, total_in;

    scanf("%f", &m);

    cm = m * 100;
    total_in = cm / 2.54;
    f = (int) (total_in / 12);
    in = (total_in - f * 12);
    
    printf("%.0f feet %.2f inch\n", f, in);

    return 0;
}