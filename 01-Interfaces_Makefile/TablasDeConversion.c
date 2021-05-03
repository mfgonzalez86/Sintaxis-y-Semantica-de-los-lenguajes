/* 01-Interfaces&Make
 *Aplicar el uso de Interfaces y MakeFile
 *Gonzalez Sintas Maria Fernanda
 *27042021
*/

#include <stdio.h>
#include "Conversion.h"
int main(void)
{
    printf("Conversion de Farenheit a Celsius\n");
    int grados;
    for (grados=0;grados<=300;grados=grados+20)
    printf("%3d %6.1f\n",grados,Celsius (grados));

    printf("Conversion de Celsius a Farenheit\n");
    float grados;
    for (grados=0;grados<=200;grados=grados+10)
    printf("%3d %6.2f\n",grados,Farenheit (grados));
}
