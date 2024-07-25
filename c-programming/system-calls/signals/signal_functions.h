#ifndef SIGNAL_FUNC_H
#define SIGNAL_FUNC_H
#include <signal.h>
#include <stdio.h>

#endif
void printSigset(FILE *of, const char *prefix, const sigset_t *sigset);
int printSigMask(FILE *of, const char *msg);
int printPendingSigs(FILE *of, const char *msg);
