#include <dbg.h>
#include <linux/limits.h>
#include <signal.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <time.h>
#include <unistd.h>

#define MAX_ARGS 128
#define MAX_LINE 8192

extern char **environ; /* Defined by libc */

void eval(char *cmdline);
bool parseline(char *buf, char **argv);
bool builtin_command(char **argv);

void sigchild_handler(int sig) {
  // printf("Caught SIGCHLD.\n");
}

int main(int argc, char *argv[]) {
  char cmdline[MAX_LINE]; // command line

  struct sigaction act;
  act.sa_handler = &sigchild_handler;
  sigfillset(&act.sa_mask);
  act.sa_flags = SA_RESTART;

  if (sigaction(SIGCHLD, &act, NULL) == -1)
    sentinel("sigaction");

  while (true) {
    // Read
    printf("> ");
    check(fgets(cmdline, MAX_LINE, stdin) != NULL || ferror(stdin),
          "fgets error.");
    if (feof(stdin))
      exit(0);
    /* printf("Cmd line: \"%s\"\n", cmdline); */
    eval(cmdline);
  }

  return 0;
error:
  return -1;
}

bool builtin_command(char **argv) {
  if (!strcmp(argv[0], "quit")) // quit command
    exit(0);
  if (!strcmp(argv[0], "&"))
    return true;
  return false;
}

void eval(char *cmdline) {
  char *arguments[ARG_MAX];
  char buf[MAX_LINE];

  strcpy(buf, cmdline);
  bool bg_enabled = parseline(buf, arguments);

  pid_t pid;
  if (arguments[0] == NULL)
    return;

  /* printf("Parent pid, ppid=%ld \n", (long)getpid()); */
  /* printf("Parent process group ID: gpid=%ld \n", (long)getpgrp()); */
  if (!builtin_command(arguments)) {
    if ((pid = fork()) == 0) {
      // Only child process can reach this
      /* printf("child process"); */
      /* printf("Child process group ID: gpid=%ld \n", (long)getpgrp()); */
      if (execvp(arguments[0], arguments) < 0) {
        printf("%s: Command not found.\n", arguments[0]);
        /* fprintf(stderr, "execve error\n"); */
        /* printf("Oh dear, something went wrong with execve()! %s\n", */
        /*        strerror(errno)); */
        exit(0);
      }
    }
    if (!bg_enabled) {
      pid_t retpid = waitpid(pid, NULL, 0);
      if (retpid < 0)
        sentinel("waitpid error.");
    } else {
      printf("%d %s\n", pid, cmdline);
    }
  }

  return;
error:
  return;
}
bool parseline(char *buf, char **argv) {
  /*
   * Parse the command line
   */
  char *token;

  int argc = 0;
  buf[strlen(buf) - 1] = ' ';
  /* printf("Origin argv[0]: \"%s\"\n", argv[0]); */
  /* printf("Buf passed in: \"%s\"\n", buf); */
  if ((token = strtok(buf, " \n")) != NULL) {
    do {
      argv[argc++] = token;
    } while ((token = strtok(NULL, " \n")) != NULL);
  }
  argv[argc] = NULL;
  if (argv[0] == NULL)
    return false;

  if (strcmp(argv[argc - 1], "&") == 0) {
    argv[--argc] = NULL;
    return true;
  }

  return false;
}
