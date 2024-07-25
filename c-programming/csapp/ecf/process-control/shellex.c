#include <dbg.h>
#include <signal.h>
#include <stdbool.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

#define MAX_ARGS 128
#define MAX_LINE 8192

extern char **environ; /* Defined by libc */

void eval(char *cmdline);
bool parseline(char *buf, char **argv);
bool builtin_command(char **argv);

int main(int argc, char *argv[]) {
  char cmdline[MAX_LINE]; // command line
  while (true) {
    // Read
    printf("> ");
    check(fgets(cmdline, MAX_LINE, stdin) != NULL || ferror(stdin),
          "fgets error.");
    if (feof(stdin))
      exit(0);

    eval(cmdline);
  }

  return 0;
error:
  return -1;
}

// If first arg is a builtin command, run it and return true
bool builtin_command(char **argv) {
  if (!strcmp(argv[0], "quit")) // quit command
    exit(0);
  if (!strcmp(argv[0], "&"))
    return true;
  return false;
}
void eval(char *cmdline) {
  char *argv[MAX_ARGS]; // Arg list execve()
  char buf[MAX_LINE];   // hold modified command line
  bool bg;              // should the job run in bg or fg
  pid_t pid;

  strcpy(buf, cmdline);
  printf("Arguments[0] passed to parseline: \"%s\"\n", argv[0]);
  bg = parseline(buf, argv);

  // User enter no character
  if (argv[0] == NULL)
    return;

  if (builtin_command(argv) == false) {
    pid = fork();
    check(pid >= 0, "Fork error");
    if (pid == 0) { // only child can reach here
      if (execve(argv[0], argv, environ) < 0) {
        printf("%s: Command not found.\n", argv[0]);
        exit(0);
      }
    }

    // Parent wait for foreground job to terminate
    if (bg == false) {
      int status;
      check(waitpid(pid, &status, 0) >= 0, "waitfg: waitpid error.");
    } else {
      log_info("%d %s", pid, cmdline);
    }
  }
  return;
error:
  return;
}

// Parse the buf command line and build into the argv array (contains of args)
bool parseline(char *buf, char **argv) {
  /* Parse the command line and build the argv array */
  char *delim; // Point to first space delimiter
  int argc;    // number of arg
  int bg;      // background jobs ?

  buf[strlen(buf) - 1] = ' ';   // Replace trailing '\n' with space
  while (*buf && (*buf == ' ')) // Ignore leading space
    buf++;

  argc = 0;
  while ((delim = strchr(buf, ' '))) {
    argv[argc++] = buf;
    *delim = '\0';
    buf = delim + 1;
    while (*buf && (*buf == ' '))
      buf++;
  }
  argv[argc] = NULL;
  if (argc == 0) // ignore blank line
    return 1;

  bg = (*argv[argc - 1] == '&') ? true : false;
  if (bg == true)
    argv[--argc] = NULL;

  return bg;
}
