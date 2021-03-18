#ifndef _HISTORY_
#define _HISTORY_

#include "tokenizer.h"
#include "history.h"
#include <string.h>

#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>


typedef struct s_Item {

  int id;

  char *str;

  struct s_Item *next;

} Item;



typedef struct s_List {

  struct s_Item *root;

} List;



/* Initialize the linked list to keep the history. */

List* init_history()
{
  
  List* list;

  list = malloc(sizeof(List));

  list->root = NULL;

  return list; 
}



/* Add a history item to the end of the list.

   List* list - the linked list

   char* str - the string to store

*/

void add_history(List *list, char *str)
  {

    // First check if our list is empty, if so allocate memory for root and them set root->str = str

    if(list->root == NULL)

      {

	list->root = malloc(sizeof(Item));

	list->root->str = malloc(sizeof(char)*strlen(str)+1);

	int n = 0;

	while(str[n])

	  {

	    list->root->str[n] = str[n];

	    n++;

	  }

	list->root->id = 1;

	return;

      }

    // Create iterator to loop through our list

    Item* iterator = list->root;

    int i = 1;

    // As long as our next item is valid keep moving through the list

    while (iterator->next)

      {

	i++;

	iterator = iterator->next;

      }

    // Once our loop finds an end point in our list allocate memory for next item and move to our next item

    iterator->next = malloc(sizeof(Item));

    iterator = iterator->next;

    // Set values to our new item in the list

    iterator->str = malloc(sizeof(char)*strlen(str)+1);

    int j = 0;

    while(str[j])

      {

	iterator->str[j] = str[j];

	j++;

      }

    iterator->id = i+1;

    iterator->next = NULL;

  }
  

  


/* Retrieve the string stored in the node where Item->id == id.

   List* list - the linked list

   int id - the id of the Item to find */

  char *get_history(List *list, int id)
  {

    Item* iterator = list->root;

    while(iterator)

      {

	if (iterator->id == id)

	  {

	    return iterator->str;

	  }

	iterator = iterator->next;

      }

    return NULL;

  }

 



/*Print the entire contents of the list. */
void print_history(List *list)
{

       Item* iterator = list->root;

       while(iterator)

	 {

	   printf("%d: ", iterator->id);

	   printf("%s", iterator->str);

	   iterator = iterator->next;

	 }

 }
 

/*Free the history list and the strings it references. */

void free_history(List *list)
   {

     Item* iterator = list->root;

     Item* temp;

     while(iterator)

       {

	 temp = iterator;

	 iterator = iterator->next;

	 free(temp->str);

	 free(temp);

       }

     // free(list);

   }


#endif
