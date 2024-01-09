#include <stdio.h>
#include <stdlib.h>

void read_line(char **line, FILE *file) {
  size_t len = 0;

  if (getline(line, &len, file) == -1) {
    if (feof(file)) {
      exit(EXIT_SUCCESS);
    } else {
      perror("failed reading line");
      exit(EXIT_FAILURE);
    }
  }
}
