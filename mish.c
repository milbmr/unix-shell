#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>

ssize_t read_line(char **line, FILE *file, char **cmd) {
  size_t len = 0;
  ssize_t read = 0;
  char *c = NULL;
  char *args[10];

  read = getline(line, &len, file);
  if (read == -1) {
    return -1;
  }

  char *copy = *line;
  c = strsep(&copy, " ");
  *cmd = c;
  printf("%p read line\n", c);

  return 0;
}

void batch_mode(char *path) {
  char *line = NULL;
  ssize_t error = 0;
  char *cmd = NULL;
  FILE *file = fopen(path, "r");

  if (file == NULL) {
    printf("Coudn't read file\n");
    return;
  }

  while ((error = read_line(&line, file, &cmd)) != -1) {
    int thread = fork();

    printf("%p main\n", cmd);
    if (thread == 0) {
      char *myargs[] = {"mish", NULL};
      execv(cmd, myargs);
    } else {
      thread = wait(NULL);
    }
  }

  if (file != NULL)
    fclose(file);
  free(line);
}

void interactive_mode() {
  size_t len = 0;
  char *line = NULL;
  char *cmd = NULL;
  ssize_t p;

  while (1) {
    printf("wish >");

    ssize_t read = read_line(&line, stdin, &cmd);

    if ((p = strcmp(line, "path")) == 0) {
    }

    int thread = fork();

    printf("%p main\n", cmd);
    if (thread == 0) {
      char *myargs[] = {"mish", NULL};
      execv(cmd, myargs);
    } else {
      thread = wait(NULL);
    }
  }

  free(line);
}

int main(int argc, char *argv[]) {
  if (argc > 2)
    return EXIT_FAILURE;

  batch_mode(argv[1]);

  return EXIT_SUCCESS;
}
