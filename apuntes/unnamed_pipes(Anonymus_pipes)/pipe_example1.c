#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char const *argv[])
{
    int fd[2];
        /* fd is file descriptor ->
            fd[0] -> read
            fd[1] -> write
        */
    if (pipe(fd) == -1)//se crea el pipe
    {
        printf("Error al abrir el pipe\n");
        return 1;
    }
    __pid_t pid = fork();//se crea el proceso hijo
    if (pid == 0)
    {/* Ahora el proceso hijo tiene su propia copia de fd[] y debe gestionarse para poder usarse */
        printf("***** CHILD PROCESS (%d)*****\n",getpid());
        printf("fd[0] -> '%d' || fd[1] -> '%d'\n",fd[0], fd[1]);
        int x;
        close(fd[0]);//se cierra el canal de lectura del hijo ya que no se va a usar
        printf("int a number: ");
        scanf("%d",&x);
        write(fd[1], &x, sizeof(x));//se manda la informacion a travez del pipe indicando que sera de x y con tamaño en bits de x
        close(fd[1]);//se cierra el canal de escritura ya que no se volverá a usar (Buena praxis)
        printf("fd[0] -> '%d' || fd[1] -> '%d'\n\n",fd[0], fd[1]);
    }
    else
    {/* El proceso padre tiene su copia de file descriptors y se deben gestionar */
        wait(NULL);//espera que el proceso hijo termine aunque no es necesario
        printf("***** PARENT PROCESS (%d)*****\n",getpid());
        printf("fd[0] -> '%d' || fd[1] -> '%d'\n",fd[0], fd[1]);
        int y;
        close(fd[1]);//se cierra el canal de escritura del padre ya que solo recibirá valores del hijo
        read(fd[0], &y, sizeof(y));//lee del pipe los valores recibido y los deposita en y
        close(fd[0]);//cierra canal de lectura cuando se deje de usar
        printf("Got from Child Proces: %d\n", y);
        printf("fd[0] -> '%d' || fd[1] -> '%d'\n",fd[0], fd[1]);
    }
    
    

    return 0;
}
/* Realmente tenemos 4 file descriptors, 2 para el proceso hijo, 2 para el proceso padre, como tal son 2 entradas y 2 salidas (una para cada proceso) es una buena praxis cerrar las conecciones de file descriptor que no usamos, en este caso queremos mandar un valor a travez del pipe desde el hijo al padre:

                       _______________________________________
       fd[1] -> WRITE (  ->  ) ->  ->  ->  ->  ->  ->  (  ->  ) fd[0] -> READ
    **CHILD PROCESS** |------|-------------------------|------| **PARENT PROCESS**
        fd[0] -> READ (  <-  ) <-  <-  <-  <-  <-  <-  (  <-  ) fd[1] -> WRITE
                      ----------------------------------------

En este caso debemos cerrar el fd de lectura del hijo, y cerrar el fd de escritura del padre:

                       _______________________________________
       fd[1] -> WRITE (  ->  ) ->  ->  ->  ->  ->  ->  (  ->  ) fd[0] -> READ
    **CHILD PROCESS** |------|-------------------------|------| **PARENT PROCESS**
         close(fd[0]) (//////) //  //  //  //  //  //  (//////) close(fd[1])
                      ----------------------------------------
 */
