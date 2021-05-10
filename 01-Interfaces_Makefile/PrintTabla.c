/* 01-Interfaces&Make
 *Aplicar el uso de Interfaces y MakeFile
 *Gonzalez Sintas Maria Fernanda
 *27042021
*/

#include <stdio.h>
#include "PrintTabla.h"

/* 
Le agrega "static" para forzar que el cliente no pueda llamar a la función aunque se 
conozaca que recibe y que devuelve---- "encapsulamiento"
*/

static void PrintFila (int col1,float col2){
    printf("%3d %6.1f\n",col1,col2);
}


void PrintTabla (float (*funcion)(int), int upper, int step){
    for (int grados=0;grados<=upper;grados=grados+step)
        PrintFila(grados,funcion (grados));

}
