/*
=========================================================
	PROGRAMA #13:
		Obtener valor de variable de ambiente con getenv()
	Archivo: c013.c
=========================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
	int i;
	char *valor;
	if (argc < 2)
	{
		return 1;
	}

	for (i = 1; i < argc; ++i)
	{
		valor = getenv(argv[i]);
		if (valor == NULL)
		{
			printf("Variable de ambiente '%s' no definida\n",argv[i] );
		}
		else
		{
			printf("Valor de '%s' = %s\n",argv[i],valor );
		}
	}

	return 0;
}