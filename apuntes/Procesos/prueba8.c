#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char const *argv[])
{
    printf("%d\n",getpid());
    __pid_t pid1;
    __pid_t pid2;
    int status1, status2;
    pid1 = fork();
    pid2 = fork();
    printf("Hello World -> Process %d - %d - %d\n",getpid(), pid1, pid2);
    waitpid(pid1, &status1, 0);
    waitpid(pid2, &status2, 0);
    return 0;
}
/* 
Hello World -> Process 47920 - 47921 - 47922
Hello World -> Process 47921 - 0 - 47923
Hello World -> Process 47922 - 47921 - 0
Hello World -> Process 47923 - 0 - 0
*/