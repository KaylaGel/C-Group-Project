/*****************************************************************************
Project Name: Event HUB 
Authors: Ryan Cleminson, Tyalr Hart, Kayla Gelman, Jacob Gowing, Dee-Jay Logozzo 

Design Brief: Event Hub is a program where people can create and edit events and patrons can join events. 

*****************************************************************************/ 

#include <stdio.h>

#define MAX_NAME_LEN 20
#define MAX_PASS_LEN 24
#define MIN_PASS_LEN 8

#define YEAR_LEN 4
#define MIN_MONTH 1
#define MAX_MONTH 12
#define MIN_DAY 1
#define MAX_DAY 31

#define MAX_PATRONS 200
#define MAX_STAFF 50
#define MAX_EVENTS 10


struct date
{
	int year;
	int month;
	int day;
	
};
typedef struct date date_t;

struct card
{
	int card_num;
	date_t exp;
	int cvv; 
	char name; 
};
typedef struct card card_t; 
	
struct person
{
	char firstname[MAX_NAME_LEN];
	char lastname[MAX_NAME_LEN];
	char password[MAX_PASS_LEN];
	date_t DOB;
};
typedef struct person person_t

struct patron
{
	person_t personal;
};
typedef struct patron patron_t;

struct staff
{
	int id;
	person_t personal;
};
typedef struct staff staff_t;

struct coord
{
	staff_t staff;
];
typedef struct coord coord_t;


struct event;
{
	char name[MAX_NAME_LEN];
	patron_t patrons[MAX_PATRONS];
	staff_t staffs[MAX_STAFF];
	coord_t coordinator;
};
typedef struct event event_t;


void print_menu(void); 
void login(person person_t); 
void create_account(person person_t); 
void add_event(event_t events, int event_count);
void display_event(event_t events, int event_count);
void search_event(event_t events, int event_count); 
void sort_event(event_t events, int event_count); 
void edit_event(event_t events); 
void add_database(event_t* events, int event_count);
void load_database(event_t* events, int* event_count);
void join_event(event_t events, int event_count); 
void encrypt_cc(card card_t); 



int main()
{
	printf("%i\n", sizeof(event_t));
	event_t events[MAX_EVENTS];
	int event_count = 0;
	return 0;
}

/************************************************************************
Author: Dee-Jay

Inputs: 
- Read details from user database 

Outputs: 
- First Name 
- Last Name 
- Password 

************************************************************************/ 
void login(person person_t)
{ 

}

/************************************************************************
Author: Ryan 

Inputs: 
- First Name 
- Last Name 
- Password 

Outputs: 
- Write to user database 



************************************************************************/ 
void create_account(person person_t)
{ 

}

/************************************************************************
Author: Kayla 

Inputs: 
- Event Details 

Outputs: 
- Write event details to file 

************************************************************************/ 
void add_event(event_t events, int event_count)
{ 

}

/************************************************************************
Author: Tyler

Inputs: 
- event counter
- new event details 

Outputs: 
- Update event details 

************************************************************************/ 
void edit_event(event_t events, int event_count)
{ 

}

/************************************************************************
Author: Jacob 

Inputs: 
- event details
- event counter 

Outputs: 
- event details 

************************************************************************/ 
void display_event(event_t events, int event_count)
{ 

}

/************************************************************************
Author: Dee-Jay

Inputs: 
- event details 
- event counter 

Outputs: 
- None 

************************************************************************/ 

void search_event(event_t events, int event_count)
{ 

}

/************************************************************************
Author: Ryan 

Inputs: 
- event details 
- event counter 

Outputs: 
- None 

************************************************************************/ 
void sort_event(event_t events, int event_count)
{ 

}

/************************************************************************
Author: Kayla

Function to write files to database 

*compression will occur here

************************************************************************/ 
void add_database(event_t* events, int event_count)
{ 
	
}

/************************************************************************
Author: Tyler 

Function to write files to database 

************************************************************************/ 
void load_database(event_t* events, int* event_count)
{

}

/************************************************************************
Author: Jacob 

Inputs: 
- event counter 
- event details 

Outputs: 
- None 

* Update database with correct number of patrons attending 

************************************************************************/ 
void join_event(event_t events, int event_count)
{ 

}

/************************************************************************
Author: Dee-Jay 

Inputs: 
- Credit card details 

Outputs: 
- encrypted credit card number

************************************************************************/ 
void encrypt_cc(card card_t)
{ 

}