#include <string.h>
#include <stdio.h>

#define BUFFER_SIZE 256

/**************************************************************
 * Function Name: caeser_cipher
 * Author(s): Ryan
 * Inputs: shift - Integer, plaintext - String, ciphertext - String Pointer
 * Outputs: ciphertext string
 * Description: Loops through each character in plain text and increments 
 *              it by "shift" number of characters
**************************************************************/
void caeser_cipher(int shift, const char* plaintext, char* ciphertext)
{
    if(shift % 26 == 0)
    {
        shift++;
    }


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
            /* convert the current_char from an ascii value to its alphabet 
            index */
            char_index = current_char - 'a';
            /* shift the char by "shift" characters */
            char_index += shift;
            char_index %= alphabet_len;
            current_char = char_index + 'a';
        }else
        if (current_char >= 'A' && current_char <= 'Z')/* upper case */
        {

            /* convert the current_char from an ascii value to its alphabet 
            index */
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

/**************************************************************
 * Function Name: xor_encrypt_file
 * Author(s): Dee-Jay
 * Inputs: key - String, Input File Pointer, Output File Pointer
 * Outputs: Encrypted File
 * Description: Reads bytes from input file, xors them with the supplied 
 *              key and writes them to the output file
**************************************************************/

int xor_encrypt_file(const char* key, FILE* input, FILE* output)
{
    rewind(input);
    rewind(output);

    char buffer[BUFFER_SIZE];
    int key_len = strlen(key);
    int bytes_read;


    /* While the end of the file hasn't been reached yet*/
    do
    {
        bytes_read = fread(buffer, sizeof(unsigned char), BUFFER_SIZE, input);
        int i;
        for (i = 0; i < bytes_read; i++)
        {
            char result;

            result = buffer[i] ^ key[i % key_len];

            /*preserve newlines*/
            if(buffer[i] == '\n' || result == '\n')
            {
                continue;
            }

            buffer[i] = result;
        }
        fwrite(buffer, sizeof(unsigned char), bytes_read, output);

    }while(bytes_read == BUFFER_SIZE);

    rewind(input);
    rewind(output);
    return 0;
}