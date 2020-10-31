#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/wait.h>

/* Uso de Exec()

int execl( const char *path, const char *arg, ...);
int execlp( const char *file, const char *arg, ...);
int execle( const char * path, const  char  *arg  ,  ..., char * const envp[]);
int execv( const char * path, char *const argv[]);
int execvp( const char *file, char *const argv[]);
int  execve(const  char  *filename, char *const argv [], char *const envp[]);


El primer argumento es el fichero ejecutable que queremos llamar. Las funciones que contienen puntos suspensivos en su declaración indican que los parámetros del ejecutable se incluirán ahí, en argumentos separados. Las funciones terminadas en “e” ( execle() y execve() ) reciben un último argumento que es un puntero a las variables de entorno. Un ejemplo sencillo nos sacará de dudas:
 */


int main(int argc, char *argv[])
{
    char *args[] = { "/bin/ls", NULL };
 
    execv("/bin/ls", args);
 
    printf("Se ha producido un error al ejecutar execv.\n");
 
    return 0;
}

/* La función elegida, execv(), recibe dos argumentos, el path al fichero ejecutable (“/bin/ls”) y un array con los parámetros que queremos pasar. Este array tiene la misma estructura que argv, es decir, su primer elemento es el propio programa que queremos llamar, luego se va rellenando con los argumentos para el programa y por último se finaliza con un puntero nulo (NULL). El printf() final no debería salir nunca, ya que para ese entonces execv() se habrá encargado de reemplazar la imagen del proceso actual con la de la llamada a “/bin/ls”.*/