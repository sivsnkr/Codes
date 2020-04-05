#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
int main()
{
    /*
    pid_t p = fork();

    if(p==0)
    {
        printf("i am in child and my parent is %d \n",getppid());
        printf("my pid is %d \n",getpid());
        
    }
    else
    {
        printf("i am in parent and my parent is %d \n",getppid());
        printf("my pid is %d \n",getpid());
        printf("my child's pid is %d \n",p);

    }
    
    */
    pid_t px = fork();
    if (px == 0)
    {
        printf("forking only the child");
        printf("\n");
        pid_t p1 = fork();
        printf("\n");
        if (p1 == 0)
        {
            printf("i am child of child");
            printf("\n");
            printf("child of child has pid %d and parent pid %d", getpid(), getppid());
            printf("\n");
            exit(0);
        }
        else
        {
            wait(NULL);
            printf("first child has pid %d and parent pid %d", getpid(), getppid());

            printf("i am child");
            printf("\n");
            exit(0);
        }
    }
    else
    {
        wait(NULL);
        printf("i am parent");
        printf("\n");
        printf("first parent has pid %d and parent pid %d", getpid(), getppid());
        printf("\n");
    }
}
