/*
=========================================================
	PROGRAMA #8:
		Uso de las constantes
	Archivo: c008.c
=========================================================
 */

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>

int main(int argc, char const *argv[])
{
	if (close(-23) ==-1)
	{
		if(errno == EBADF) {
		 	printf("Descriptor de fichero incorrecto\n");
		 }
		 else if(errno == EIO) {
		 	printf("Error fisico de E/S\n");
		 }
		 else {
		 	printf("Error: %s\n",strerror(errno) );
		 } 
	}
	return 0;
}