#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>

void handler(int sig)
{
    printf("ok\n");
    _exit(0);
}
int main(int argc, char *argv[])
{
    signal(SIGINT, handler);
    sleep(10);
}