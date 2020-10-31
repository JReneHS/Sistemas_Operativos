/*
=========================================================
	PROGRAMA #3:
		Llamada al sistema con error y Fork()
	Archivo: c003.c
=========================================================
 */

#include <unistd.h>
#include <stdio.h>

int main(int argc, char const *argv[])
{
	if (fork() == -1)
	{
		printf("La llamada a fork ha fallado ...\n");
		return 1;
	}
	else
	{
		printf("La llamada a fork se ha realizado con exito ...\n");
		return 0;
	}
}
/*
La llamada a fork se ha realizado con exito ...
La llamada a fork se ha realizado con exito ...
*/