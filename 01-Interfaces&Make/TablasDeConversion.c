/* 01-Interfaces&Make
 *Aplicar el uso de Interfaces y MakeFile
 *Gonzalez Sintas Maria Fernanda
 *27042021
*/

#include <stdio.h>
#include "Conversion.h"
int main(void)
{
    int fahr;
    for (fahr=0;fahr<=300;fahr=fahr+20)
    printf("%3d %6.1f\n",fahr,ObtenerCelciusDeFahr (fahr));
}