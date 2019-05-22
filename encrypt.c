#include <string.h>

void encrypt_plaintext(char* plaintext, char* ciphertext)
{
    strcpy(ciphertext, plaintext);

    int text_len = strlen(ciphertext);

    int i;
    for (i = 0; i < text_len; i++)
    {
        ciphertext[i]++;
    }

    return;
}