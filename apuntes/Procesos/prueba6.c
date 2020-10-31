#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

/* La función system():
La forma más sencilla de invocar una orden UNIX desde un programa en C es mediante la función system, que toma como único parámetro la orden que quieren ejecutar. Reconoce redirecciones, expresiones regulares, conductos (pipes), etc. Por ejemplo, la línea

system("ls -l /usr/include/*.h >pepe.txt")

ejecuta la cadena pasada como parámetro tal y como si la hubiéramos tecleado desde la consola. La función system se limita a lanzar un shell hijo pasándole como parámetro de entrada la cadena suministrada en la función.

La forma de más bajo nivel para ejecutar una orden consiste en lanzar a ejecución el programa deseado mediante alguna de las llamadas al sistema que empiezan por exec. Existen varias modalidades que difieren en la forma de pasar los parámetros al programa (aunque realmente se trata de una sola llamada al sistema UNIX). */

int main(int argc, char const *argv[])
{
    printf("Hola\n");
    system("ls -l");
    system("ps | grep system > salida.txt");
    printf("chau\n");
    system("cat salida.txt");
    return 0;
}
