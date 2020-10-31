#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

/* Fork y wait:
Para crear nuevos procesos, el UNIX dispone únicamente de una llamada al sistema, fork, sin ningún tipo de parámetros. Su prototipo es:

int fork();

Al llamar a esta función se crea un nuevo proceso (proceso hijo), idéntico en código y datos al proceso que ha realizado la llamada (proceso padre). Los espacios de memoria del padre y el hijo son disjuntos, por lo que el proceso hijo es una copia idéntica del padre que a partir de ese momento sigue su vida separada, sin afectar a la memoria del padre; y viceversa.

Siendo más concretos, las variables del proceso padre son inicialmente las mismas que las del hijo. Pero si cualquiera de los dos procesos altera una variable, el cambio sólo repercute en su copia local. Padre e hijo no comparten memoria.

El punto del programa donde el proceso hijo comienza su ejecución es justo en el retorno de la función fork, al igual que ocurre con el padre.
 */
 
//Función principal
int main(int argc, char **argv[])
{
    //Declaramos variables
    int status,pid;
    
    //Si fork() es igual a 0 entonces es hijo
    if((pid=fork()) == 0)
    {
        printf("\nSoy hijo, mi pid es: %d\n",getpid());
        printf("\nMi padre tiene el pid: %d\n",getppid());
    }
    //Sino entonces es Padre
    else
    {
        //Con el wait esperamos a que el hijo finalice.
        wait(&status);
        printf("\nSoy Padre, mi pid es: %d\n",getpid());
        printf("\ntengo que esperar a mi hijo: %d\n",pid);
        printf("\nmi hijo termino con un estado: %d\n",status);
    }
    return 0;
}
/*
Soy hijo, mi pid es: 49317

Mi padre tiene el pid: 49316

Soy Padre, mi pid es: 49316

tengo que esperar a mi hijo: 49317

mi hijo termino con un estado: 0
*/