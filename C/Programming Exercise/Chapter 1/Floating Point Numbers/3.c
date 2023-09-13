#include <stdio.h>

int main()
{
    float meter, feet, inch;

    scanf("%f", &meter);

    feet = meter * 3.28084;
    inch = (feet - (int) feet) * 12;

    printf("%.0f feet %.2f inch", feet, inch);

    return 0;
}