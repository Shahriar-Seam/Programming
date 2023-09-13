#include <stdio.h>

int main()
{
    int return_value;
    char *filename = "photo.jpg";

    return_value = remove(filename);

    if (return_value != 0) {
        perror("File removal failed");
        return 1;
    }

    printf("%s is removed successfully\n", filename);

    return 0;
}