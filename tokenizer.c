#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>



int main(char *argv[]){

  char *string = malloc(sizeof(argv[1]));
  
  int i;
  for (i = 0; i < sizeof(argv[1]); i++){
    string[i] = argv[1][i];
  }
  
  return 0;

}
