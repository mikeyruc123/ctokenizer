#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

void output(); // prints out the token with proper formatting
void oType(); // determines the type of operator

enum type {word, integer, octal, hex, float, other};

int main(int argc, char *argv[]){

  int length = strlen(argv[1]);
  char *input;
  strcopy(input, argv[1]);
  char *start;
  char *end;
  char *current;

  int i;
  for (i = 0; i < length; i++){
    current = input[i];

    if (current >= 0 && current <= ' '){ // delimeter
      end = current[-1];

    }


  }

  return 0;

}

void output(enum type type, char *start, char *end){

  if (type == word){
    printf("word: ");
  } else if (type == integer){
    printf("integer: ");
  } else if (type == octal){
    printf("octal integer: ");
  } else if (type == hex){
    printf("hexidecimal integer: ");
  } else if (type == float){
    printf("floating point: ");
  } else {
    // something for operators and such

    if (&start == &end){
      printf("%s: %s", oType(&start), &start);
    } else {
      // some more crazy shit
    }

    return;
  }

  char *current = start;
  while (&current != end[1]){
    printf("%c", current);
  }

  printf("%c", '\n');

}
