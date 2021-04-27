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
    int fahr;
    for (fahr=0;fahr<=300;fahr=fahr+20)
    printf("%3d %6.1f\n",fahr,Celsius (fahr));

    printf("Conversion de Celsius a Farenheit\n");
    float cels;
    for (cels=-17.8;cels<=148.9;cels=cels+11.1)
    printf("%6.1f %3d\n",cels,Farenheit (cels));
}
