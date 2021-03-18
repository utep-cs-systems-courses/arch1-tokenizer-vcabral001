

#include "tokenizer.h"



#include <stdlib.h>

#include <stdio.h>

int string_length(char* str)

{

  int counter = 0;

  while(*str != '\0' && *str != '\n')

    {

      counter++;

      *str++;

    }

  return counter;

}



/*

    In order to make use of this function in our word start

    and word end function we will make a SPACE a non valid 

    character. 

*/

char is_valid_character(char c)

{

  return (c >= 33 && c <= 125) ? 1 : 0;

}



/*

    Function to find the begining of a word based on a position in a string given.

*/

int word_start(char* str, int pos)

{

  while (pos >= 0 &&  pos < string_length(str))

    {

      // If we are in a valid character and our previous character is not valid return pos.

      if (is_valid_character(str[pos]) && !is_valid_character(str[pos-1]))

	{

	  return pos;

	}

      // If we are in a space move foward.

      if (!is_valid_character(str[pos]))

	{

	  pos++;

	  continue;

	}

      // Move back since we are in the middle of a string.

      pos--;

    }



  return -1;

}



int word_end(char* str, int pos)

{

  while(pos >= 0 && pos < string_length(str))

    {

      // If we are at a valid character an our next position is a in valid character return pos.

      if (is_valid_character(str[pos]) && !is_valid_character(str[pos+1]))

	{

	  return pos;

	}

      // Move foward since we are in the middle of a string or in an ivalid pos.

      pos++;

    }

  return -1;

}



int count_words(char* str)

{

  int i = 0;

  int word_counter = 0;

  while(i < string_length(str))

    {

      // find starting position of word.

      int start = word_start(str, i);

      int end = word_end(str, i);



      if (start == -1 && end == -1)

	{

	  break;

	}



      word_counter++;

      i = end + 1;

    }

  return word_counter;

}



void print_tokens(char** ppStr)

{

  while (*ppStr)

    {

      printf("[%s],",*ppStr);

      *ppStr++;

    }

  printf("\n");

}



void free_tokens(char** ppStr)

{

  while (*ppStr++)

    {

      free(*ppStr);

    }

  //free(ppStr);

}



char** tokenize(char* pStr)

{

  int word_count = count_words(pStr);

  char** ppStr = malloc((sizeof(char*) * word_count) + 1 );

  int i = 0;

  int wi = 0;

  while (i < word_count)

    {

      int start = word_start(pStr, wi);

      int end = word_end(pStr, start);

      char* temp = malloc(sizeof(char) * (end-start) + 1);

      int j = 0;

      while(start <= end)

	{

	  *(temp+j) = *(pStr+start);

	  j++;

	  start++;

	}



      *(ppStr+i) = temp;

      i++;

      wi = end + 1;

    }

  return ppStr;

}
