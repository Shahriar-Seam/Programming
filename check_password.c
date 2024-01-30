#include "hash.h"
#include <conio.h>

int main()
{
    char str[100], str2[100], *encrypted_str1, *encrypted_str2;

    puts("Enter password: ");
    gets(str);

    puts("Enter password again: ");
    gets(str2);

    encrypted_str1 = encrypt(str);
    encrypted_str2 = encrypt(str2);

    if (strcmp(encrypted_str1, encrypted_str2) == 0) {
        puts("You may enter");
    }
    else {
        puts("Ja vag");
    }

    puts("\nHashes:");
    puts(encrypted_str1);
    puts(encrypted_str2);

    getch();

    return 0;
}

// gcc -o check_password check_password.c -lssl -lcrypto -lws2_32 && sha256_example.exe