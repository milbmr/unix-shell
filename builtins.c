#include "execution.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int msh_cd(char **args);
int msh_exit(char **args);

char *builtins[] = {"cd", "exit"};

int builtins_num() { return sizeof(builtins) / sizeof(char *); }

int (*builtins_func[])(char **args) = {
    &msh_cd,
    &msh_exit,
};

int msh_cd(char **args) {
  if (args[1] == NULL) {
    printf("argument expected\n");
  } else {
    if (chdir(args[1]) != 0) {
      perror("error change directory");
    }
  }

  return 1;
}

int msh_exit(char **args) { return 0; }

int msh_exec(char **args) {
  int i;

  if (args[0] == NULL) {
    return 1;
  }

  for (i = 0; i < builtins_num(); i++) {
    if (strcmp(builtins[i], args[0]) == 0) {
      return (*builtins_func[i])(args);
    }
  }

  return execution(args);
}
