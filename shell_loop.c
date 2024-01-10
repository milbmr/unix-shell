#include "builtins.h"
#include "read_line.h"
#include "split_line.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>

void shell_loop(FILE *file) {
  char *line = NULL;
  char **tokens;
  int status;

  do {
    read_line(&line, file);
    tokens = split_line(line);
    status = msh_exec(tokens);

    free(line);
    free(tokens);
  } while (status);
}
