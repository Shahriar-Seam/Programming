#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/sha.h>

int hash_string(const char *input_string, unsigned char **output_string)
{
    int outlen = SHA256_DIGEST_LENGTH;

    *output_string = (unsigned char *) malloc(outlen);

    if (*output_string == NULL) {
        perror("Failed to allocate memory for output string.");

        return -1;
    }

    if (SHA256((unsigned char *) input_string, strlen(input_string), *output_string) == NULL) {
        perror("Failed to hash string.");

        free(*output_string);

        return -1;
    }

    return outlen;
}

void copy_encrypted_text(const unsigned char *hashed_text, int hashed_len, char **encrypted_text)
{
    int strlen = hashed_len * 2 + 1;
    int i;

    *encrypted_text = (char *) malloc(strlen);
    if (*encrypted_text == NULL) {
        perror("Failed to allocate memory for encrypted string.");
        return;
    }

    for (i = 0; i < hashed_len; i++) {
        sprintf(*encrypted_text + i * 2, "%02x", hashed_text[i]);
    }

    (*encrypted_text)[strlen - 1] = '\0';
}

char *encrypt(char *plain_text) {
    unsigned char *hashed_text;
    int hashed_len = hash_string(plain_text, &hashed_text);
    char *encrypted_text;

    if (hashed_len == -1) {
        exit(-1);
    }

    copy_encrypted_text(hashed_text, hashed_len, &encrypted_text);

    free(hashed_text);

    return encrypted_text;
}
