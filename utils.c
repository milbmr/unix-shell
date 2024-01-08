#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char **spit(char *string) {
  char *pch;
  char **arr = malloc(5 * sizeof(char *));
  pch = strtok(string, " ,.-");

  while (pch != NULL) {
    pch = strtok(NULL, " ,.-");
  }

  return 0;
}
