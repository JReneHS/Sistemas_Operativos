/*
=========================================================
	PROGRAMA #6/7:
		Imprimir los errores en "stderr"
			en lugar de en "stdio"
	Archivo: c006_7.c
=========================================================
 */

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>

int main(int argc, char const *argv[])
{
	if (close(23) == -1)
	{
		perror(NULL);
		perror("Ha petado: ");
		return 1;
	}
	return 0;
}