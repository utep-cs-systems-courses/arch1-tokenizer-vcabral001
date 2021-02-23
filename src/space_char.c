#include tokenizer.h

int space_char(char c){
  while(c != EOF){
    if(c == 0){
       return False;
    }
    else if(c == '\t' || ' ')
        return True;
       
  }

}
