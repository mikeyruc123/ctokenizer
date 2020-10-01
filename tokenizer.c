#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

int noTokens(); //iterates through input string and returns the number of tokens within; needed for malloc efficiency

int main(int argc, char *argv[]){

  int length = strlen(argv[1]);
  char **tokens = malloc(length);
  char *start;
  char *end;

  return 0;

}
