
Usuario Github: mfgonzalez86  
Legajo: 1209176  
Apellido: Gonzalez Sintas  
Nombre:  Maria Fernanda
Nro y titulo del trabajo: 01-Interfaces&Makefile  
#Se trabajo con Visual Studio Code, compilador C99
Enunciado: 

1. La primera tarea es investigar las funcionalidades y opciones que su
compilador presenta para limitar el inicio y fin de las fases de traducción.  

Son habituales las siguientes extensiones o sufijos de los nombres de archivo:  
 
.c	fuente en C  
.i	C preprocesado  
.s	fuente en lenguaje ensamblador  
.o	código objeto  
.h	archivo para preprocesador (encabezados), no suele figurar en la linea de comando de gcc

Opciones.  
## - c  
realiza preprocesamiento y compilación, obteniento el archivo en código objeto; no realiza el enlazado.  
## - E  
realiza solamente el preprocesamiento, enviando el resultado a la salida estándar.  (Punto 1)
## -o archivo  
indica el nombre del archivo de salida, cualesquiera sean las etapas cumplidas.  
## -g  
incluye en el ejecutable generado la información necesaria para poder rastrear los errores usando un depurador, tal como GDB (GNU Debugger).  
## -v  
muestra los comandos ejecutados en cada etapa de compilación y la versión del compilador. Es un informe muy detallado.  

2. La siguiente tarea es poner en uso lo que se encontró. Para eso se debe
transcribir al readme.md cada comando ejecutado y su resultado o error
correspondiente a la siguiente secuencia de pasos. También en readme.md se
vuelcan las conclusiones y se resuelven los puntos solicitados. Para claridad,
mantener en readme.md la misma numeración de la secuencia de pasos.  

# 7.3.1. Secuencia de Pasos  

Se parte de un archivo fuente que es corregido y refinado en sucesivos pasos.
Es importante no saltearse pasos para mantener la correlación, ya que el estado
dejado por el paso anterior es necesario para el siguiente.  
  
## 1. Preprocesador
### punto (a)  Escribir hello2.c, que es una variante de hello.c:

De acuerdo a lo investigado, en la terminal se escribió el comando:  
gcc -E hello2.c -o hello2.i  
Al disparar dicho comando ,se creo el archivo hello2.i  

### punto (b) Preprocesar hello2.c, no compilar, y generar hello2.i. Analizar su contenido. ¿Qué conclusiones saca?

En las primeras líneas se puede observar los prototipos de todas las funciones que contiene el header de la biblioteca std input/ output.  
Por ejemplo se observa lo siguiente:  
#461 "c:\\mingw\\include\\stdio.h" 3
 __attribute__((__cdecl__)) __attribute__((__nothrow__)) int fprintf (FILE *, const char *, ...);  
 __attribute__((__cdecl__)) __attribute__((__nothrow__)) int printf (const char *, ...);  
 __attribute__((__cdecl__)) __attribute__((__nothrow__)) int sprintf (char *, const char *, ...);  
 __attribute__((__cdecl__)) __attribute__((__nothrow__)) int vfprintf (FILE *, const char *, __builtin_va_list);  
 __attribute__((__cdecl__)) __attribute__((__nothrow__)) int vprintf (const char *, __builtin_va_list);  
 __attribute__((__cdecl__)) __attribute__((__nothrow__)) int vsprintf (char *, const char *, __builtin_va_list);  

Por lo que entiendo (#) está indicando una línea incluida en la dirección del archivo header que se atribuye.  
  
Al finalizar los prototipos del stdio.h se puede observar las líneas del código ingresadas ya procesadas.   
Originalmente el código fuente es el siguiente:  
 #include <stdio.h>  
int/*medio*/main(void){  
int i=42;  
 prontf("La respuesta es %d\n");  
Errores observados:  
*Le falta la } para contener las declaraciones de la función  
*Invoca una función que no se encuentra en la biblioteca std (prontf)   
*Tiene comentario entre el int y el main.    
Lo que se espera es que pegue los prototipos del header y reemplace el comentario entre el int y el main por un espacio.  
Por lo que aprendimos en clase el preprocesador no tiene demasiada inteligencia, no evalúa situaciones sino que hace reemplazos, por lo tanto, no se espera indique error alguno en esta etapa.  

archivo  hello.i  
#2 "hello2.c"  
int main(void){  
int i=42;  
 prontf("La respuesta es %d\n");  
   
 Efectivamente, el comentario entre medio se reemplazó. 
 Por otro lado, el preprocesador no indicó ninguna falla dado que en la terminal se realizó la acción sin respuesta  
 PS C:\Users\rowa\Desktop\Facultad\SyL\ejercicios\01-Interfaces_Make\SyL\02-FasesDeTraduccionYErrores> gcc -E hello2.c -o hello2.i  
PS C:\Users\rowa\Desktop\Facultad\SyL\ejercicios\01-Interfaces_Make\SyL\02-FasesDeTraduccionYErrores>  

### punto (c). Escribir hello3.c, una nueva variante:
Archivo hello3.c en la carpeta del ejercicio   
### punto (d). Investigar e indicar la semántica de la primera línea.  
Se investigó en el libro "El lenguaje de programación C" de Kernighan & Ritchie  
Capítulo 7  
int printf(char *format, arg1, arg2, ...)  (de a cuerdo al libro)  
int printf(const char * restrict s, ...) (de a cuerdo al ejercicio)    
Por otro lado se investigó que implica que en vez de pasar un puntero *format se pasara un puntero *restrict s.  
Lo que se encontró es que el atribujo "restrict" indica al compilador que si se definen distintos punteros corresponden a distintos espacios en memoria.    

Del libro se aprendió lo siguiente:  
printf convierte, da formato e imprime sus argumentos en la salida estándar bajo el control de format, en este caso el format sería bajo el atributo de Restrict, y regresa el número de caracteres impresos.  
La cadena de formato contiene dos tipos de objetos: caracteres ordinarios, que son copiados al flujo de salida, y especificaciones de conversión, cada uno de los cuales
causa la conversión e impresión de los siguientes argumentos sucesivos de printf. En nuestro caso los argumentos sucesivos se indican directamente con el "...". 
En el caso del libro primero muestra los arg1 y arg2 indicando con "..." que se puede continuar declarando.  
Cada especificación de conversión comienza con un % y termina con un carácter de conversión. Por eljemplo %3d o %6.1f, casos que hemos usado en ejercicios anteriores.  
printf emplea su primer argumento para decidir cuántos argumentos le siguen y cuáles son sus tipos, printf se confundirá y se obtendrán resultados erróneos si no hay suficientes argumentos o si tienen tipos incorrectos.  

### punto (e)  Preprocesar hello3.c, no compilar, y generar hello3.i. Buscar diferencias entre hello3.c y hello3.i.

Solamente se observa que en el archivo hello3.i se agregaron 4 líneas al comienzo. Se estima es parte de la construcción del archivo fuente al preprocesado.   
#1 "hello3.c"  
#1 "<built-in>"  
#1 "<command-line>"  
#1 "hello3.c"  
int printf(const char * restrict s, ...);  
int main(void){  
int i=42;  
 prontf("La respuesta es %d\n");  





