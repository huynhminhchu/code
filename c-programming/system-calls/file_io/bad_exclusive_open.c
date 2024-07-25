#include <sys/stat.h>
#include <fcntl.h>
#include <tlpi_hdr.h>

int main(int argc, char *argv[])
{
    int fd;
    fd = open(argv[1], O_WRONLY);
    if (fd != -1) {
        //Open succeeded = file already exists
        printf("[PID %ld] File \"%s\" already exists\n", (long) getpid(), argv[1]);
        close(fd);
    } else {
        if (errno != ENOENT){
            // Other error
            errExit("open");
        } else {
            // File doesn't exist
            printf("[PID %ld] File \"%s\" doesn't exist yet\n", (long) getpid(), argv[1]);
            if (argc > 2) { /* Delay between check and create */
                sleep(5); /* Suspend execution for 5 seconds */
                printf("[PID %ld] Done sleeping\n", (long) getpid());
            }
            fd = open(argv[1], O_WRONLY | O_CREAT | O_EXCL, S_IRUSR | S_IWUSR);
            //without O_EXCL, the OS will do 2 operations sequentially: check if the file doesn't exist first, then create it.
            if (fd == -1)
                errExit("open");
            printf("[PID %ld] Created file \"%s\" exclusively\n", (long) getpid(), argv[1]);
        }
    }
}