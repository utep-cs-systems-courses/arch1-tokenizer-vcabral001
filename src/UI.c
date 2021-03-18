#include <stdio.h>

#include <stdlib.h>

#include "tokenizer.h"

#include "history.h"



int main()

{

  List* history = init_history();

  char str[100];

  char* pStr;

  pStr= str;

  while(1)

    {

      printf("$ ");

      fgets(str, sizeof str, stdin);

      if(pStr[0]=='!')

	{

	  int num = pStr[1] - '0';

	  if(!num)

	    {

	      print_history(history);

	      continue;

	    }

	  char* pStrHistory = get_history(history,num);

	  int i = 0;

	  int j = 0;

	  while(pStrHistory[i])

	    {

	      pStr[j++] = pStrHistory[i++];

	    }

	}



      printf("%s", pStr);

      char** ppStr = tokenize(pStr);

      printf("Tokens: ");

      print_tokens(ppStr);

      free_tokens(ppStr);

      add_history(history, pStr);

    }

  return 0;

}


