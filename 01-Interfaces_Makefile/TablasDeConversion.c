/* 01-Interfaces&Make
 *Aplicar el uso de Interfaces y MakeFile
 *Gonzalez Sintas Maria Fernanda
 *27042021
*/

#include <stdio.h>
#include "Conversion.h"
#include "PrintTabla.h"
int main(void)
{
    const int upper=300;
    const int step=20;

    printf("\nConversion de Farenheit a Celsius\n");
     PrintTabla(Celsius,upper,step);

    printf("\nConversion de Celsius a Farenheit\n");
      PrintTabla(Farenheit,upper,step);

}
