#include <stdio.h>
#include <stdlib.h>

ssize_t read_line(char **line, FILE *file, char **cmd) {
  size_t len = 0;
  ssize_t read = 0;
  char *c = NULL;
  char *args[10];

  if (getline(line, &len, file) == -1) {
    if (feof(file)) {
      return 0;
    } else {
      perror("failed reading line");
      return -1;
    }
  }

  return 0;
}
