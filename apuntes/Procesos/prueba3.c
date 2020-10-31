#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>

int main(int argc, char const *argv[])
{
    pid_t pid1;
    pid_t pid2;
    int status1, status2;
    if ((pid1 = fork()) == 0)
    { /* Proceso hijo (Primera generacion) */
        if ((pid2 = fork()) == 0)
        { /* Proceso hijo (Segunda generacion) */
            printf("\nSoy el nieto (%d, hijo de %d)\n", getpid(), getppid());
        } 
        else
        {
            wait(&status2);
            printf("Soy el padre (%d, hijo de %d)\n", getpid(), getppid());
        }
    }
    else
    {
        wait(&status1);
        printf("Soy el Abuelo (%d, hijo de %d)\n", getpid(), getppid());
    }
    return 0;
}
/*
Soy el nieto (48806, hijo de 48805)
Soy el padre (48805, hijo de 48804)
Soy el Abuelo (48804, hijo de 48792)
*/