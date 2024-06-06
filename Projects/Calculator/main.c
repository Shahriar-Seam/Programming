#include <stdio.h>
#include <math.h>
#include <conio.h>

int main()
{
    printf("-----------------------------------------------------------------------------\n");
    printf("--------------------Created By: Ibnul Abrar Shahriar Seam--------------------\n");
    printf("--------A simple calculator program written in C programming language--------\n");
    printf("-----------------------------------------------------------------------------\n");
    printf("\n\n");
    printf("Available operations: +, -, *, /, ^\n\n");

    double a, b;
    char operator;
    int t;

    printf("How many operations do you want to do?\n=> ");
    scanf("%d", &t);
    printf("\n\n");

    while (t--) {    
        printf("Enter expression (use format: num1 operator num2): ");
        scanf("%lf", &a);
        scanf(" %c", &operator);
        scanf("%lf", &b);

        switch (operator)
        {
            case '+':
                printf("%g %c %g = %g\n\n", a, operator, b, a + b);
                break;
            
            case '-':
                printf("%g %c %g = %g\n\n", a, operator, b, a - b);
                break;
            
            case '*':
                printf("%g %c %g = %g\n\n", a, operator, b, a * b);
                break;
            
            case '/':
                printf("%g %c %g = %g\n\n", a, operator, b, a / b);
                break;
            
            case '^':
                printf("%g %c %g = %g\n\n", a, operator, b, pow(a, b));
                break;
            
            default:
                printf("\nInvalid Input.\nPLease try again.\n\n");
        }
    }

    printf("Press any key to exit.\n");
    getch();

    return 0;
}