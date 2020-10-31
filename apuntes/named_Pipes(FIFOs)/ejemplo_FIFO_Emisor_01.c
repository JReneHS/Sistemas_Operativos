#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

#include <sys/stat.h> //librería para uso de Named Pipes
#include <sys/types.h> //extension de typos de dato
#include <errno.h> //libreria de errores
#include <fcntl.h> //libreria para abrir, leer y escribir en el pipe

#define NUMELEM 10
#define nameFIFO "sum"

int main(int argc, char const *argv[])
{
    int sendValue[NUMELEM]; //array de elementos a enviar
    int i; //variable de uso multiple
    srand(time(NULL)); //crear numeros aleatorios en base al tiempo

    for (i = 0; i < NUMELEM; i++)
    {
        sendValue[i] = rand() % 21; //numeros aleatorios entre 0 ~ 20
    }

// creacion el named Pipe, regresa 0 si se crea de forma correcta, -1 en caso de que haya un error
    int statusFIFO = mkfifo(nameFIFO, S_IRWXG | S_IRWXO | S_IRWXU); //equivale a escribir el bit 0777
    if (statusFIFO == -1) //si ya se creo el FIFO da error
    {
        if (errno != EEXIST) //Por eso es necesario identificar si fue error por existencia o por otra cosa
        {
            printf("Error al crear el Pipe con nombre\n");
            return 1;
        }
    }

/* Apertura para escritura del Named Pipe */
    printf("Abriendo...\n");
    int fd = open(nameFIFO, O_WRONLY); //Abriendo el FIFO en modo de solo escritura
    if (fd == -1)
    {
        printf("Error al abrir el archivo\n");
        return 1;
    }

/* Escritura de la informacion en el Named Pipe */
    for (i = 0; i < NUMELEM; i++)
    {
        if (write(fd, &sendValue[i], sizeof(int)) == -1) //Envio de los valores del array al FIFO.
        {
            printf("Error al escribir en el Pipe con nombre\n");
            return 1;
        }
        printf("Escribiendo: %d\n",sendValue[i]);
    }

    close(fd); //Cerrando la coneccion al FIFO
    printf("Cerrado\n");

/* Apertura para Lectura del Named Pipe */
    printf("Abriendo...\n");
    fd = open(nameFIFO, O_RDONLY); //apertura del FIFO para solo lectura
    if (fd == -1) //revision de errores
    {
        printf("Error al abrir el archivo\n");
        return 1;
    }

/* Lectura de la informacion del Named Pipe */
    if (read(fd, &i, sizeof(int)) == -1) //Lecutura del FIFO hacia el array, con un tamaña de int
    {// Validacion de errores de lectura
        printf("Error al leer en el Pipe con nombre\n");
        return 1;
    }
    printf("La suma de los elementos es: %d\n",i);
    close(fd); //Cerrando la coneccion al FIFO
    printf("Cerrado\n");
    sleep(20);
    return 0;
}
