#include <stdio.h>

int main()
{
    double loan_amount, interest_rate, number_of_years, total_amount, monthly_amount;

    printf("Enter loan amount: ");
    scanf("%lf", &loan_amount);
    
    printf("Enter interest rate: ");
    scanf("%lf", &interest_rate);
    
    printf("Enter number of years: ");
    scanf("%lf", &number_of_years);

    total_amount = loan_amount + loan_amount * interest_rate * number_of_years / 100.0;
    monthly_amount = total_amount / (number_of_years * 12);

    printf("Total amount: %g\n", total_amount);
    printf("Monthly amount: %g\n", monthly_amount);

    return 0;
}