/*
=========================================================
	PROGRAMA #4:
		Consultar el valor numérico 
			de la variable global "errno"
	Archivo: c004.c
=========================================================
 */

#include <stdio.h>
#include <unistd.h>
#include <errno.h>

int main(int argc, char const *argv[])
{
// Llamada al sistema para cerrar un fichero que no está abierto
	if (close(23) == -1)
	 {
	 	printf("Motivo de error de la ultima llama al sistema %d\n",errno );
// Regresa el numero de error 9
	 	return 1;
	 } 
	return 0;
}