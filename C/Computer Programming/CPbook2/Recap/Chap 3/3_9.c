#include <stdio.h>

int main()
{
    int return_value;
    char *filename = "3_9_removable.txt";

    return_value = remove(filename);

    if (return_value != 0) {
        perror("File removal failed");
        return 1;
    }

    printf("%s was removed successfully\n", filename);

    return_value = remove(filename);

    if (return_value != 0) {
        perror("File removal failed");
        return 1;
    }

    printf("%s was removed successfully\n", filename);

    return 0;
}