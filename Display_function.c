void display_event(event_t events[], int event_count) {
    char display_choice[MAX_NAME_LEN];
    int i;

    printf("Please enter the event name to view the event, or enter 'all' to view all events\n");
    scanf("%s", display_choice);


    /* to display all events */
    if (event_count >= 0){

        if (strcmp(display_choice, "all") == 0) {
            int space[2];
            int i, j;
            int temp_count
            printf("Event Name           Event Type Date       Coordinator\n");
            printf("-------------------- ---------- ---------- --------------------\n");

            for (i = 0; i <= event_count; i++) {

                printf("%s", events[i].name);
                space[0] = MAX_NAME_LEN - strlen(event[i].name);
                for (j = 0; j <= space[0]; j++) {
                    printf(" ");
                }

                printf("%s", events[i].event_type);
                space[0] = 10 - strlen(event[i].event_type);
                for (j = 0; j <= space[0]; j++) {
                    printf(" ");
                }

                printf("%02d/%02d/%02d", events[i].day, events[i].month, events[i].year);

                printf(" ");

                printf("%s", events[i].coordinator);
                space[0] = MAX_NAME_LEN - strlen(event[i].coordinator);
                for (j = 0; j <= space[0]; j++) {
                    printf(" ");
                }
            }
        }

            /*for a specific event*/
        else {
            int spaces[2];
            int j;

            for (i = 0; i <= event_count; i++) {
                if (strcmp(display_choice, events[i].event_name) == 0) {
                    temp_count = i;
                    printf("Event Name           Event Type Date       Coordinator\n");
                    printf("-------------------- ---------- ---------- --------------------\n");

                    printf("%s", events[i].name);
                    space[0] = MAX_NAME_LEN - strlen(event[i].name);
                    for (j = 0; j <= spaces[0]; j++) {
                        printf(" ");
                    }

                    printf("%s", events[i].event_type);
                    space[0] = 10 - strlen(event[i].event_type);
                    for (j = 0; j <= spaces[0]; j++) {
                        printf(" ");
                    }

                    printf("%02d/%02d/%02d", events[i].day, events[i].month, events[i].year);

                    printf(" ");

                    printf("%s", events[i].coordinator);
                    space[0] = MAX_NAME_LEN - strlen(event[i].coordinator);
                    for (j = 0; j <= spaces[0]; j++) {
                        printf(" ");
                    }

                    printf("\nNumber of Patrons   Number of Staff Event Time Free or Paid\n");
                    printf("------------------- ------------------- ---------- ------------\n")

                    printf("%d", events[i].num_patrons);
                    int par_len = (int) (Math.log10(events[i].num_patrons) + 1);
                    spaces[0] = MAX_NAME_LEN - par_len;
                    for (j = 0; j <= spaces[0]; j++) {
                        print(" ");
                    }

                    printf("%d", events[i].num_staff);
                    int sta_len = (int) (Math.log10(events[i].num_staff) + 1);
                    spaces[0] = MAX_NAME_LEN - sta_len;
                    for (j = 0; j <= spaces[0]; j++) {
                        printf(" ");
                    }

                    printf("%02d:%02d      "), events[i].hour, events[i].minute;

                    if (events[i].free_event == 1) {
                        printf("Yes");
                    }

                    else (events[i].free_event == 0){
                        printf("No");
                    }

                    printed = 1;
                } else if (i == event_count && printed == 0) {
                    printf("No events found");
                }
            }

        }


        /* if no events can be found */
    else {
        printf("No events found");
    }
}
}
