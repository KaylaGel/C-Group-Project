#include <stdio.h>
#include <stdlib.h>

void get_user_login(char* username, char* password)
{
    printf("Username: ");
    scanf("%s", username);

    printf("Password: ");
    scanf("%s", password);
    return;
}

void get_event_login(char* event_id, char* event_password)
{
    printf("Event ID: ");
    scanf("%s", event_id);

    printf("Password: ");
    scanf("%s", event_password);
    return;
}

int scan_int(void)
{
    char* input = malloc(MAX_INT_LEN + 1);
    while(1)
    {
        /* TODO: account for spaces in user input */
        scanf("%s", input);
        if( valid_int(input) )
        {
            return convert_int(input);
        }else
        {
            printf("Not a valid number\n");
            printf("Please input a valid number: \n");
            return scan_int();
        }
    }

}