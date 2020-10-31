#include "shared_Memory.h"
#include "shared_Memory.c"

int main(int argc, char const *argv[])
{
    int estado = destruir_bloque_Memoria();
    if (estado == IPC_ERROR)
    {
        printf("Error al destruir el bloque de memoria\n");
    }
    else
    {
        printf("Bloque de memoria destruido\n");
    }
    sleep(20);
    return 0;
}
