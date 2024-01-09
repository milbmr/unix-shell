#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
int execution(char **args) {
  pid_t pid, wpid;

  pid = fork();

  if (pid == 0) {
    execvp(args[0], args);
  } else {
    wpid = waitpid(pid, NULL, WUNTRACED);
  }

  return 0;
}
