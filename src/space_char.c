#include "tokenizer.h"
#include <stdio.h>
#include "history.h"

#define BOOL char
#define TRUE 1
#define FALSE 0

int space_char(char c){
  while(c != EOF){
    if(c == 0){
       return FALSE;
    }
    else if(c == '\t' || ' ')
        return TRUE;
       
  }

}
