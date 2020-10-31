#include "shared_memory.h"

int main(int argc, char const *argv[])
{
    int shmid; //identificador asociado a la zona de memoria
    key_t key; //llave de acceso al mecanismo IPC
    char* shm; //Direccion donde está unida el segmento de memoria

    if (argc == 1)
    {
        printf("Ingrese una cadena a leer\n");
        return 1;
    }
    
/* Obtencion de la Key a partir de un archivo y una letra */
    key = ftok("shared_memory.h", 0);
    if (key == IPC_ERROR)
    {
        printf("Error al crear llave\n");
        return 1;
    }

/* Obtencion del ID de la zona de memoria */
    shmid = shmget(key, SHSIZE, IPC_CREAT | 0777); //Creacion del espacio de Memoria y permisos
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

/* Envio del mensaje hacia el emisor */
    printf("Enviando al Bloque de Memoria: \"%s\"\n",argv[1]);
    strncpy(shm, argv[1], SHSIZE);

/* Espera de recepcion de token para continuar */
    while (*shm != '*')
    {
        printf("Esperando...\n");
        sleep(1);
    }

/* Eliminacion de la seccion de memoria */
    shmctl(shmid, IPC_RMID, NULL);
    printf("Eliminando Memoria Compartida\n");
    sleep(20);
    return 0;
}
