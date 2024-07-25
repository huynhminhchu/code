#include <ctype.h>
#include <tlpi_hdr.h>
#include <sys/stat.h>
#include <fcntl.h>

#define printable(ch) (isprint((unsigned char) ch) ? ch : '#')
#define BUF_SIZE 1024

static void usageError(char *progName, char *msg, int opt)
{
    if (msg != NULL && opt != 0)
        fprintf(stderr, "%s (-%c)\n", msg, printable(opt));
    fprintf(stderr, "Usage: %s [-p arg] [-x]\n", progName);
    exit(EXIT_FAILURE);
}

int main(int argc, char *argv[])
{
    int opt;
    int inputFd, outputFd, openFlags;
    mode_t filePerms;
    char buf[BUF_SIZE + 1];
    ssize_t numRead;
    char *fileName;
    fileName = NULL;

    openFlags = O_CREAT | O_WRONLY | O_APPEND;
    filePerms = S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH; //rw-rw-rw
    while ((opt = getopt(argc, argv, ":a:")) != -1){
        switch (opt)
        {
        case 'a':
            fileName = optarg;
            break;
        case ':':
            usageError(argv[0], "Missing argument", optopt);
        case '?':
            usageError(argv[0], "Unregconized option", optopt);
        default:
            fatal("Unexpected case in switch()");

        }
    }

    outputFd = open(fileName, openFlags, filePerms);

    while ( (numRead = read(STDIN_FILENO, buf, BUF_SIZE)) > 0 )
    {
        buf[numRead] = '\0';
        if (write(outputFd, buf, numRead) != numRead)
            fatal("couldn't write whole buffer");
        printf("%s", buf);
        
    }

    if (numRead == -1)
        errExit("read");

    exit(EXIT_SUCCESS);
}