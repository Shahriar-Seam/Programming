#include <stdio.h>

int main()
{
    // Declare variable
    int i;

    // Run the loop to print 1000 to 1
    for (i = 1000; i > 0; i--) {
        printf("%d\t", i);

        // Print newline after every 5 number
        if (i % 5 == 1) {
            printf("\n");
        }
    }

    return 0;
}

// LightOJ wanted space. I gave it Tab. -_-