#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int execution(char **args) {
  pid_t pid, wpid;

  pid = fork();
  if (pid == 0) {
    if (execvp(args[0], args) == -1) {
      return 0;
    }
  } else {
    wpid = waitpid(pid, NULL, WUNTRACED);
  }

  return 1;
}
