#include <string.h>
#include <stdio.h>

void caeser_cipher(const int shift, const char* plaintext, char* ciphertext)
{
    strcpy(ciphertext, plaintext);

    int text_len = strlen(ciphertext);
    int char_index;
    int alphabet_len = ('z' + 1) - 'a';

    int i;
    for (i = 0; i < text_len; i++)
    {
        char current_char = plaintext[i];

        if (current_char >= 'a' && current_char <= 'z')/* lower case */
        {
            /* convert the current_char from an ascii value to its alphabet index */
            char_index = current_char - 'a';
            /* shift the char by "shift" characters */
            char_index += shift;
            char_index %= alphabet_len;
            current_char = char_index + 'a';
        }else
        if (current_char >= 'A' && current_char <= 'Z')/* upper case */
        {

            /* convert the current_char from an ascii value to its alphabet index */
            char_index = current_char - 'A';
            /* shift the char by "shift" characters */
            char_index += shift;
            char_index %= alphabet_len;
            current_char = char_index + 'A';
        }

        ciphertext[i] = current_char;

    }

    return;
}

int xor_encrypt_file(const char* key, const char* input_filename, const char* output_filename)
{
    FILE* input;
    FILE* output;

    char buffer;
    int index = 0;
    int key_len = strlen(key);

    input = fopen(input_filename, "rb");
    output = fopen(output_filename, "wb");

    if(input == NULL || output == NULL)
    {
        printf("Error: failure opening file\n");
        return 1;
    }

    /* While the end of the file hasn't been reached yet*/
    while( ( buffer = fgetc(input) ) != EOF )
    {
        buffer ^= key[index % key_len];
        fputc(buffer, output);
        index++;
    }

    fclose(input);
    fclose(output);

    return 0;
}