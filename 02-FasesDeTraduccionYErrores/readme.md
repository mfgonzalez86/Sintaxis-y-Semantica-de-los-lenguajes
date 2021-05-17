
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
## -S 
transforma el código C en el lenguaje ensamblador propio del procesador de nuestra máquina.  
## as
  $ as -o nombre.o nombre.s  
crea el archivo en código objeto .o a partir del archivo en lenguaje ensamblador .s sin vincular.  

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

## 2. Compilación  
### punto (a)  Compilar el resultado y generar hello3.s, no ensamblar  
PS C:\Users\rowa\Desktop\Facultad\SyL\ejercicios\01-Interfaces_Make\SyL\02-FasesDeTraduccionYErrores> gcc -S hello3.i -o hello3.s  
hello3.c: In function 'main':  
hello3.c:4:2: warning: implicit declaration of function 'prontf'; did you mean 'printf'? [-Wimplicit-function-declaration]  
    4 |  prontf("La respuesta es %d\n");  
      |  ^~~~~~  
      |  printf  
hello3.c:4:2: error: expected declaration or statement at end of input  

El error indica que espera fin de instrucción. Se entiende que corresponde a la falta de } en la función main.

### punto (b). Corregir solo los errores, no los warnings, en el nuevo archivo hello4.c y empezar de nuevo, generar hello4.s, no ensamblar  

int printf(const char * restrict s, ...);  
int main(void){  
int i=42;  
 prontf("La respuesta es %d\n");  
 }  

se actualizó el archivo hello.c agregando la "}".  

En la terminal se volvieron a correr los comandos  
PS C:\Users\rowa\Desktop\Facultad\SyL\ejercicios\01-Interfaces_Make\SyL\02-FasesDeTraduccionYErrores> gcc -E hello4.c -o hello4.i  
PS C:\Users\rowa\Desktop\Facultad\SyL\ejercicios\01-Interfaces_Make\SyL\02-FasesDeTraduccionYErrores> gcc -S hello4.i -o hello4.s  
hello4.c: In function 'main':  
hello4.c:4:2: warning: implicit declaration of function 'prontf'; did you mean 'printf'? [-Wimplicit-function-declaration]  
    4 |  prontf("La respuesta es %d\n");  
      |  ^~~~~~  
      |  printf  
PS C:\Users\rowa\Desktop\Facultad\SyL\ejercicios\01-Interfaces_Make\SyL\02-FasesDeTraduccionYErrores>   
Se observa en warming pero se pudo compilar.  


### punto (c). Leer hello4.s, investigar sobrelenguajeensamblador,eindicardeformar sintética cual es el objetivo de ese código  

	.file	"hello4.c" 
	.text  
	.def	___main;	.scl	2;	.type	32;	.endef  
	.section .rdata,"dr"  
LC0:  
	.ascii "La respuesta es %d\12\0"  
	.text  
	.globl	_main  
	.def	_main;	.scl	2;	.type	32;	.endef  
_main:  
LFB0:  
	.cfi_startproc  
	pushl	%ebp  
	.cfi_def_cfa_offset 8  
	.cfi_offset 5, -8  
	movl	%esp, %ebp  
	.cfi_def_cfa_register 5  
	andl	$-16, %esp  
	subl	$32, %esp  
	call	___main  
	movl	$42, 28(%esp)  
	movl	$LC0, (%esp)  
	call	_prontf  
	movl	$0, %eax  
	leave  
	.cfi_restore 5  
	.cfi_def_cfa 4, 4  
	ret  
	.cfi_endproc  
LFE0:  
	.ident	"GCC: (MinGW.org GCC Build-2) 9.2.0"  
	.def	_prontf;	.scl	2;	.type	32;	.endef  
 
 * Me falta averiguar
### punto (d). Ensamblar hello4.s en hello4.o, no vincular  
En la terminal:  
PS C:\Users\rowa\Desktop\Facultad\SyL\ejercicios\01-Interfaces_Make\SyL\02-FasesDeTraduccionYErrores> as -o hello4.o hello4.s  
PS C:\Users\rowa\Desktop\Facultad\SyL\ejercicios\01-Interfaces_Make\SyL\02-FasesDeTraduccionYErrores>   

No se detectaron errores ni warnings.

## 3. Vinculación 
### punto (a). Vincular hello4.o con la biblioteca estándar y generar el ejecutable.  
En la terminal:  
PS C:\Users\rowa\Desktop\Facultad\SyL\ejercicios\01-Interfaces_Make\SyL\02-FasesDeTraduccionYErrores>  gcc -o hello4.exe hello4.o  
c:/mingw/bin/../lib/gcc/mingw32/9.2.0/../../../../mingw32/bin/ld.exe: hello4.o:hello4.c:(.text+0x1e): undefined reference to 'prontf'  
collect2.exe: error: ld returned 1 exit status  
PS C:\Users\rowa\Desktop\Facultad\SyL\ejercicios\01-Interfaces_Make\SyL\02-FasesDeTraduccionYErrores>    
El error indica que no encuentra la funcion "prontf"  
### punto (b). Corregir en hello5.c y generar el ejecutable. Solo corregir lo necesario para que vincule.
Se corrige cambiando la invocacion de "prontf" por "printf"  
En la terminal:  
Siguiendo los pasos..  
PS C:\Users\rowa\Desktop\Facultad\SyL\ejercicios\01-Interfaces_Make\SyL\02-FasesDeTraduccionYErrores> gcc -E hello5.c -o hello5.i  
PS C:\Users\rowa\Desktop\Facultad\SyL\ejercicios\01-Interfaces_Make\SyL\02-FasesDeTraduccionYErrores> gcc -S hello5.i -o hello5.s  
PS C:\Users\rowa\Desktop\Facultad\SyL\ejercicios\01-Interfaces_Make\SyL\02-FasesDeTraduccionYErrores> as -o hello5.o hello5.s  
PS C:\Users\rowa\Desktop\Facultad\SyL\ejercicios\01-Interfaces_Make\SyL\02-FasesDeTraduccionYErrores> gcc -o hello5.exe hello5.o  
PS C:\Users\rowa\Desktop\Facultad\SyL\ejercicios\01-Interfaces_Make\SyL\02-FasesDeTraduccionYErrores>   

Dado que en este punto ya se compiló y vinculó, también podríamos escribir directamente en la consola    
 gcc hello5.c  -o hello5  

## punto (c). Ejecutar y analizar el resultado.
En la terminal:  
PS C:\Users\rowa\Desktop\Facultad\SyL\ejercicios\01-Interfaces_Make\SyL\02-FasesDeTraduccionYErrores> ./hello5.exe  
La respuesta es 4200688  
PS C:\Users\rowa\Desktop\Facultad\SyL\ejercicios\01-Interfaces_Make\SyL\02-FasesDeTraduccionYErrores>   

La frase "la respuesta es" es parte de los carácteres ordinarios los cuales son copiados al flujo de salida.   
El valor 4200688 no corresponde a la variable declarada dado que al printf no le pasamos por argumento la misma.  
Creo que puede llegar a ser como una "reserva de espacio en memoria" por el formato %d que estamos indicando.  
Para evaluar lo anteriormente planteado se volvió a compilar hello5 pero en vez de %d se paso %X, según el libro (página 206) x, X int; número hexadecimal sin signo (con un 0x o 0X inicial, usando abcdef o ABCDEF para 10,... 15)  
La resuesta que se obtuvo fue:  
PS C:\Users\rowa\Desktop\Facultad\SyL\ejercicios\01-Interfaces_Make\SyL\02-FasesDeTraduccionYErrores> ./hello5.exe  
La respuesta es 4018F0  

Se volvió a compilar  pero esta vez indicando %3.1f en vez de %d.  
Se obtuvo lo siguiente:  
PS C:\Users\rowa\Desktop\Facultad\SyL\ejercicios\01-Interfaces_Make\SyL\02-FasesDeTraduccionYErrores> ./hello5.exe  
La respuesta es 0.0  
Dado que se imprimió 0.0 se descarta la conclusión anterior y se establece que los valores que imprime pueden llegar a pertenecer a espacios en memeoria aleatorios. Dado que no se ha pasado argumento alguno, citando nuevamente el libro con el que trabajamos en clase:  
Una advertencia: printf emplea su primer argumento para decidir cuántos  
argumentos le siguen y cuáles son sus tipos, printf se confundirá y se obtendrán  
resultados erróneos si no hay suficientes argumentos o si tienen tipos incorrectos.  

## 4. Corrección de Bug
### punto (a). Corregir en hello6.c y empezar de nuevo; verificar que funciona como se espera.
Se cambió la línea de  
 printf("La respuesta es %d\n")  
por  
 printf("La respuesta es %d\n",i)  

PS C:\Users\rowa\Desktop\Facultad\SyL\ejercicios\01-Interfaces_Make\SyL\02-FasesDeTraduccionYErrores>  gcc hello6.c  -o hello6    
PS C:\Users\rowa\Desktop\Facultad\SyL\ejercicios\01-Interfaces_Make\SyL\02-FasesDeTraduccionYErrores> ./hello6.exe  
La respuesta es 42  

En este caso se pasa como argumento la variable i la cuál tiene asignada el valor de 42, al correr el ejecutable se muestra el valor correcto.  

## 5. Remoción de prototipo
### Punto (a). Escribir hello7.c, una nueva variante:
int main(void){  
 int i=42;  
 printf("La respuesta es %d\n", i);  
}  

### Punto (b). Explicar porqué funciona.
printf es una función que forma parte de la biblioteca std la cual se vincula en el Linker.   
No es "extrictamente necesario" declarar el prototipo (header) para que funcione, si es lo más adecuado dado que evitamos tener errores en tiempo de ejecución si no estamos usando correctamente una función. Los argunmentos que se tranfieren al invocar la función están correctos.  











