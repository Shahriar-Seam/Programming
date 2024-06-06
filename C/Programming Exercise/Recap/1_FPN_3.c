#include <stdio.h>

int main()
{
    double meter, feet, inch;

    printf("Enter height (in meter): ");
    scanf("%lf", &meter);

    feet = meter * 3.280839895;

    inch = (feet - (int) feet) * 12;

    printf("height: %d feet %.2lf inch\n", (int) feet, inch);

    return 0;
}