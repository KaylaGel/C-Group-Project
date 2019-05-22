#include "structs.h" /* event_t */

void search_event(event_t events, int event_count, char[] event_name)
{
  int i;

  for (i = 1; i < event_count; i++)
  {
    if (event_name == events.name[i])
    {
      printf("Event Name> %s", event.name[i]);
      /* print any other neccessary details */
    }
  }
  return;
}
