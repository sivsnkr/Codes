#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sys/stat.h>
int main(void)
{
    if (mkfifo("fifo", 0600) < 0)
    {
        perror("failed to create named pipe");
        exit(2);
    }
    pid_t pid = fork();

    switch (pid)
    {
    case -1:
        perror("failed to create fork");
        break;
    case 0:
    {
        int fd;
        close(1);
        fd = open("fifo", O_WRONLY);
        char *argv[1] = {"ls"};
        if (fd < 0)
        {
            perror("Failed to open named fifo");
            exit(2);
        }
        // else if (fd != 1)
        // {
        //     printf("Uncorrect write descripter\n");
        //     exit(2);
        // }
        // execvp("ls", argv);
        write(fd, "Shiv says hello", 100);
        exit(2);
    }
    default:
    {
        int fd, fd1;
        close(0);
        fd = open("fifo", O_RDONLY);
        fd1 = open("fifo", O_RDONLY);

        printf("fd: %d, fd1: %d\n", fd, fd1);
        char buffer[100], buffer1[100];
        if (fd < 0)
        {
            perror("Failed to open named fifo");
            exit(2);
        }
        // else if (fd != 0)
        // {
        //     printf("Uncorrect read descripter\n");
        //     exit(2);
        // }
        read(fd, buffer, 100);
        read(fd1, buffer1, 100);
        printf("Buffer: %s\n", buffer);
        printf("Buffer1: %s\n", buffer1);
        // execlp("tr", "tr", "a-z", "A-Z");
        exit(2);
    }
    }
}