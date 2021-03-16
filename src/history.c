#ifndef _HISTORY_

#define _HISTORY_



typedef struct s_Item {

  int id;

  char *str;

  struct s_Item *next;

} Item;



typedef struct s_List {

  struct s_Item *root;

} List;



/* Initialize the linked list to keep the history. */

List* init_history(){
  list.size = size;
  list.data = data;
}



/* Add a history item to the end of the list.

   List* list - the linked list

   char* str - the string to store

*/

void add_history(List *list, char *str){
  
  int size = arraylist_get_size(*list);

  char *new_data;



  new_data = realloc(list.data, (size + 1) * sizeof new_data[0]);



  if (new_data)

    {

      new_data[size] = value;

      arraylist_set_data_collection(list, new_data);

      ++list.size;

    }


/* Retrieve the string stored in the node where Item->id == id.

   List* list - the linked list

   int id - the id of the Item to find */

char *get_history(List *list, int id);

   return id;


/ *Print the entire contents of the list. */

void print_history(List *list){
  for(int i=0; i< list;i++){
    printf(%c, list[i]);
  }
 }

/ *Free the history list and the strings it references. */

void free_history(List *list);



#endif