#include "shared_Memory.h"
#include "shared_Memory.c"

int main(int argc, char const *argv[])
{
    char *bloque = atar_bloque_Memoria();
    if (bloque == NULL)
    {
        printf("Error al crear el bloque");
        return 1;
    }

    printf("Escribiendo: \"%s\"\n",argv[1]);
    strncpy(bloque,argv[1], B_SIZE);

    desatar_bloque_memoria(bloque);
    sleep(20);
    return 0;
}
