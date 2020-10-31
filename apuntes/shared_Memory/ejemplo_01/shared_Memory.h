#ifndef shared_Memory_h
#define shared_Memory_h

    #include <stdio.h>
    #include <stdlib.h>
    #include <unistd.h>
    #include <string.h>
    #include <sys/types.h>
    #include <sys/ipc.h>
    #include <sys/shm.h>

    #define B_SIZE 4096
    #define FILENAME "shared_Memory.h"
    #define IPC_ERROR -1

    char *atar_bloque_Memoria();
    int desatar_bloque_memoria(char *bloque);
    int destruir_bloque_Memoria();
#endif