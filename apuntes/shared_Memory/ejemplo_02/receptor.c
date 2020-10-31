#include "shared_memory.h"

int main(int argc, char const *argv[])
{
sleep(1);
    int shmid; //identificador asociado a la zona de memoria
    key_t key; //llave de acceso al mecanismo IPC
    char* shm; //Direccion donde está unida el segmento de memoria

/* Obtencion de la Key a partir de un archivo y una letra */
    key = ftok("shared_memory.h", 0);
    if (key == IPC_ERROR)
    {
        printf("Error al crear llave\n");
        return 1;
    }

/* Obtencion del ID de la zona de memoria */
    shmid = shmget(key, SHSIZE, 0777); //Permiso de lectura, escritura y busqueda a todos
    if (shmid == IPC_ERROR)
    {
        printf("Error al asignar segmento de memoria\n");
        return 1;  
    }

/* Obtencion de la direccion de Memoria atada */
    shm = shmat(shmid, NULL, 0);
    if (shm == (char*)IPC_ERROR)
    {
        printf("Error al enlazar (atar) segmento de memoria\n");
        return 1;  
    }
    printf("Leyendo de Bloque: \"%s\"\n",shm);

/* Envio de un Token para que el proceso Emisor termine */
    strncpy(shm, "*", SHSIZE);

/* Eliminacion de la seccion de memoria */
    shmctl(shmid, IPC_RMID, NULL);
    printf("Eliminando Memoria Compartida\n");
    sleep(20);
    return 0;
}
