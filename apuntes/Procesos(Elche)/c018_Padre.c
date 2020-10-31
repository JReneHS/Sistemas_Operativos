#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char const *argv[])
{
    int pid; /*En pid almacenaremos el no deidentificación de proceso devuelto por fork()*/
    int pExec;
    pid=fork(); /*fork() crea un clon del proceso primitivo*/
    switch(pid)
    {
        case -1: /*fork devuelve -1 en caso de error*/
        printf("\nNo se puede crear proceso hijo");
        exit(0); /* salimos al S.O.*/

        case 0: /*el valor 0 es asignado al hijo, mientras que el */
        /* proceso padre recibe el número de identificación del hijo*/
        printf("\n número de identificación del proceso HIJO %d", pid);
        pExec = execl("./c018_Hijo","c018_Hijo",NULL); /* ejecutamos el hijo */

        default:
        waitpid(pid, NULL, 0);
        printf("\n número de identificación del PADRE %d\n", pid);
        exit(0);
    }
}