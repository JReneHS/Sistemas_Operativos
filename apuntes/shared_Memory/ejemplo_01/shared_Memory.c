#include "shared_Memory.h"

static int obtener_llave_bloque()
{
    key_t key;
    key = ftok(FILENAME,0);
    if (key == IPC_ERROR)
    {
        printf("Error al crear llave\n");
        return 1;
    }
    return shmget(key,B_SIZE, 0777 |IPC_CREAT);
}

char *atar_bloque_Memoria()
{
    int shmid = obtener_llave_bloque(FILENAME, B_SIZE);
    char* res;

    if (shmid == IPC_ERROR)
    {
        return NULL;
    }

    res = shmat(shmid,NULL,0);
    if (res == (char*)IPC_ERROR)
    {
        return NULL;
    }
    return res;
}

int desatar_bloque_memoria(char *bloque)
{
    return shmdt(bloque);
}

int destruir_bloque_Memoria()
{
    int shmid = obtener_llave_bloque();
    if (shmid == IPC_ERROR)
    {
        return IPC_ERROR;
    }
    return shmctl(shmid, IPC_RMID, NULL);
}
