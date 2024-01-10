#include "read_line.h"
#include "split_line.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>

void batch_mode(char *path) {
  FILE *file = fopen(path, "r");

  if (file == NULL) {
    printf("Coudn't read file\n");
    return;
  }
}

void interactive_mode() {
  size_t len = 0;
  char *line = NULL;
  char *cmd = NULL;
  ssize_t p;

  free(line);
}

int main(int argc, char *argv[]) {
  if (argc > 2)
    return EXIT_FAILURE;

  batch_mode(argv[1]);

  return EXIT_SUCCESS;
}
