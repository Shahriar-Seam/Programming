#include <stdio.h>
#include <math.h>

int main()
{
    char equation[50]; // Input string for the quadratic equation
    double a = 0, b = 0, c = 0; // Coefficients of the equation
    double signA = 1, signB = 1, signC = 1; // Signs for the coefficients
    double discriminant, root1, root2, realPart, imaginaryPart; // Variables for discriminant and roots
    int index = 0; // Index for parsing the input string

    // Prompt the user to input the equation
    printf("Format the equation in the form ax^2 + bx + c = 0\n");
    gets(equation); // Read the input equation

    // Check and set the sign for coefficient 'a'
    if (equation[0] == '-') {
        signA = -1;
        index++;
    }

    // Parse coefficient 'a'
    for (index; equation[index] != 'x'; index++) {
        a *= 10;
        a += equation[index] - '0';
    }

    index += 4; // Move past "x^2 "

    // Check and set the sign for coefficient 'b'
    if (equation[index] == '-') {
        signB = -1;
    }
    
    index += 2; // Move past "+ " or "- "

    // Parse coefficient 'b'
    for (index; equation[index] != 'x'; index++) {
        b *= 10;
        b += equation[index] - '0';
    }

    index += 2; // Move past "x "

    // Check and set the sign for coefficient 'c'
    if (equation[index] == '-') {
        signC = -1;
    }
    
    index += 2; // Move past "+ " or "- "

    // Parse coefficient 'c'
    for (index; equation[index] != ' '; index++) {
        c *= 10;
        c += equation[index] - '0';
    }

    // Apply the signs to the coefficients
    a *= signA;
    b *= signB;
    c *= signC;

    // Calculate the discriminant
    discriminant = b * b - 4 * a * c;

    // Determine the nature of the roots based on the discriminant
    if (discriminant < 0) {
        // Complex roots
        realPart = (-b) / (2 * a);
        imaginaryPart = sqrt(-discriminant) / (2 * a);

        // Ensure the imaginary part is positive
        if (imaginaryPart < 0) {
            imaginaryPart *= -1;
        }

        // Two complex roots where one is the complement of the other
        printf("x1 = %g + %gi\nx2 = %g - %gi\n", realPart, imaginaryPart, realPart, imaginaryPart);
    }
    else if (discriminant > 0) {
        // Two distinct real roots
        root1 = (-b + sqrt(discriminant)) / (2 * a);
        root2 = (-b - sqrt(discriminant)) / (2 * a);

        printf("x1 = %g\nx2 = %g\n", root1, root2);
    }
    else {
        // One real root
        root1 = root2 = (-b) / (2 * a);
        printf("x = %g\n", root1);
    }

    return 0; // Indicate that the program ended successfully
}
