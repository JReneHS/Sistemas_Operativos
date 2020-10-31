/*
=========================================================
	PROGRAMA #5:
		Consultar el mensaje asociado al error 
			de la variable global "errno"
	Archivo: c005.c
=========================================================
 */

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>

int main(int argc, char const *argv[])
{
// Llamada al sistema para cerrar un fichero que no está abierto
	if (close(23) == -1)
	 {
	 	printf("Motivo de error de la ultima llama al sistema %d\n %s \n",errno, strerror(errno) );
// Regresa el numero de error 9
	 	return 1;
	 } 
	return 0;
}