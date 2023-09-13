#include <stdio.h>

int main()
{
    int t;
    double c, f, k;

    printf("Choose one:\n1. Celsius To Fahrenheit (working)\n2. Fahrenheit to Celsius (working)\n3. Fahrenheit to Kelvin\n4. Kelvin to Fahrenheit\n\n--> ");
    scanf("%d", &t);

    if (t == 1) {
        printf("Enter temp in Celsius: ");
        scanf("%lf", &c);

        f = (c * 1.8) + 32;
        printf("Temp in Fahrenheit is %.2lf.\n", f);
    }
    if (t == 2) {
        printf("Enter temp in Fahrenheit: ");
        scanf("%lf", &f);

        c = (f - 32) * 5 / 9;
        printf("Temp in Celsius is %.2lf.\n", c);
    }
    else if (t != 1 || t != 2) {
        printf("Invalid input or code not added yet.\n");
    }

    return 0;
}