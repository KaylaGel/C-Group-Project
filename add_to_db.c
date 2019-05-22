#include "structs.h"
#define DB_Name "Database.txt"

/************************************************************************
Author: Kayla

Function to write files to database

*compression will occur here

************************************************************************/
void add_database(event_t* events, int event_count)
{
  /*write all event details to add_database*/
  /*write all logins to database*/
  int i;
  FILE* fp = NULL;

    fp = fopen(DB_NAME, "+w");
    if (fp == NULL)
    {
        printf("Write error\n");
        return;
    }

    // event database
   for (i = 0; i <= event_count; i++)
   {
      fprintf(fp,%s,event[i].name); /*What other variables need to be saved to the file*/
   }
   fclose(fp);

   /* To Do */
   /* User Database --> Save usernames, encypted passwords*/
   return;


}
