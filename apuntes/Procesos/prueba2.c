#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>

int main(int argc, char const *argv[]) {
    pid_t pid1;
    pid_t pid2;
    int status1, status2;

    if ((pid1 = fork()) == 0) {
        printf("\nSoy el proceso hijo 1(%d hijo de %d)\n\n", getpid(),getppid());
    } else {
        if ((pid2 = fork()) == 0) {
            printf("\nSoy el proceso hijo 2(%d hijo de %d)\n\n", getpid(),getppid());
        } else {
            waitpid(pid1, &status1, 0);
            waitpid(pid2, &status2, 0);
            printf("Soy el proceso Padre (%d hijo de %d)\n\n", getpid(),getppid());
        }
    }
    return 0;
}
/*
Soy el proceso hijo 1(48627 hijo de 48626)


Soy el proceso hijo 2(48628 hijo de 48626)

Soy el proceso Padre (48626 hijo de 48411)
*/