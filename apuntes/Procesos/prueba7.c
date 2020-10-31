#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
/* El sistema operativo UNIX ofrece una llamada al sistema llamada ‘exec’ para lanzar a ejecución un programa, almacenado en forma de fichero. Aunque en el fondo sólo existe una llamada, las bibliotecas estándares del C disponen de varias funciones, todas comenzando por ‘exec’ que se diferencian en la manera en que se pasan parámetros al programa.

La versión típica cuando se conoce a priori el número de argumentos que se van a entregar al programa se denomina execl. Su sintaxis es

int execl ( char* fichero, char* arg0, char* arg1, ... , 0 ); */
 
//Función principal
int main(int argc, char **argv[])
{
    //Declaramos variables
    int status;
    __pid_t pid;
    //Si fork() es igual a 0 entonces es hijo
    if((pid=fork()==0))
    {
        printf("hola soy el proceso hijo\n");
        //Cabe destacar que una llamada a execl reemplaza el proceso actual, es por eso que lo cree dentro de un proceso hijo
        execl("/bin/ls","ls",(char *)NULL);
    }
    //Sino entonces es Padre
    else
    {
        wait(&status);
        printf("soy el padre, se termino el listado\n");
    }
    return 0;
}
/*
hola soy el proceso hijo
prueba1    prueba3.c  prueba6    prueba8.c
prueba1.c  prueba4    prueba6.c  prueba9
prueba2    prueba4.c  prueba7    prueba9.c
prueba2.c  prueba5    prueba7.c  salida.txt
prueba3    prueba5.c  prueba8
soy el padre, se termino el listado
*/