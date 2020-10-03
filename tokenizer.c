#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

void output(); // prints out the token with proper formatting
enum type tType(); // given current character, determines whether it conflicts with the existing type; returns new type
//void oType(); // determines the type of operator

enum type {word, integer, octal, hex, float, other};

int main(int argc, char *argv[]){

  int length = strlen(argv[1]);
  char *input;
  strcopy(input, argv[1]);
  char *start;
  char *end;
  char *current;
  enum type type;
  enum type curType;

  int i;
  for (i = 0; i < length; i++){
    current = input[i];

    if (&current >= 0 && &current <= ' '){ // delimeter
      if (type != NULL){
        end = current[-1];
        output(type, start, end);
        // do some stuff, print token
      }

      start = current[1];
      end = NULL;
      type = tType(current, NULL);

    } else if (isalnum(&current)){
      curType = tType(current, type);
      if (type == NULL){
        type = curType;
      } else if (type != curType){
        // start new token
        output(type, start, end);
        type = curType;
        start = current;
        end = NULL;
      } else {
        // continue token, type == curType
        end = current;
      }
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

enum type tType(character *current, enum type type){ // used to compare the current type to the result to
                                                     // determine whether or not a new token must be started
  if (isalpha(current)){
    if (type == word){ // word gets another word character
      return word;
    } else if (type == hex){ // hex gets a word character; determines if it is hex
      if (ishex(current)){
        return hex;
      } else { // start a new word token
        return word;
      }
    } else {
      // create new token
      return word;
    }
  } else if (isdigit(current)){
    if (current >= '0' && current <= '7' && type == octal){ //
      return octal;

    } else if (current[1] == 'x'){
      // start of new hex
      return hex;
    } else if (type == hex){
      return hex;
    } else if (current == '0' && type == NULL){ // if the start of the string is 0, assume octal
      return octal;
    } else if (type == integer){
      return integer;
    } else if (type == float){
      return float;
    } else {
      return word;
    }
  } else if (&current == '.'){
    if (type == integer){
      return float;
    } else {
      // some type of operator
      oType(&current);
      return -1;
    }
  }
}
