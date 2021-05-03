/* 01-Interfaces&Make
 *Aplicar el uso de Interfaces y MakeFile
 *Gonzalez Sintas Maria Fernanda
 *27042021
*/

#include "Conversion.h"

/*Convierte de Farenheit a Celsius*/
float Celsius (int far){
return (5.0/9.0)*(far-32);
}

/*Convierte de Celsius a Farenheit*/
float Farenheit (int cel){
    return (9.0/5.0*cel)+32;
}
