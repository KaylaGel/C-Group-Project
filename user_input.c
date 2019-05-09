#include <stdio.h>

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

