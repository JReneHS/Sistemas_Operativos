/*
=========================================================
	PROGRAMA #9:
		Tabla de variables de ambiente
	Archivo: c009.c
=========================================================
 */

#include <stdio.h>

int main(int argc, char const *argv[], char *env[])
{
	int i;
	for (i = 0; env[i] != NULL ;i++)
	{
		printf("%s\n",env[i]);
	}
	return 0;
}