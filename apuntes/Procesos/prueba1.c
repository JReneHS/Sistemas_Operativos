#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>

int main(int argc, char const *argv[])
{
    pid_t pid;
    if ((pid =  fork()) == 0)
    {
        printf("\nSoy el proceso hijo (%d, hijo de %d)\n", getpid(), getppid());
    } else
    {
        printf("Soy el proceso padre (%d, hijo de %d)\n", getpid(), getppid());
    }

    return 0;
}
/*
Soy el proceso padre (48208, hijo de 47902)
Soy el proceso hijo (48209, hijo de 48208)
*/
/*
Soy el proceso padre (48196, hijo de 47902)

Soy el proceso hijo (48197, hijo de 48196)
*/