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

    printf("Leyendo de Bloque: \"%s\"\n",bloque);

    desatar_bloque_memoria(bloque);
    sleep(20);
    return 0;
}
