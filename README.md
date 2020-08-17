# SUDOKU - UN JUEGO DE LÓGICA

El juego consiste en un tablero de 9x9, dividido en regiones de 3x3 llamados
cuadrantes. Cada casilla puede contener valores del 1-9 respetando las
siguientes reglas:

a) El valor debe ser único en su fila
b) El valor debe ser único en su columna
c) El valor debe ser único en su cuadrante

## CONSIDERACIONES DE COMPILACIÓN

El programa fue desarrollado principalmente en entorno MAC (OSX 10.7 - gcc 4.2)
donde se realizaron las ultimas pruebas de funcionamiento, a pesar de ello el
programa fue pensado para poder ser compilado en entornos unix (de preferencia)
y windows con opciones que se especifican en el apartado de "Instrucciones de
Compilación". Aunque por la falta de pruebas en las demás plataformas
disponibles el programa pueda presentar algún error inesperado.

## INSTRUCCIONES DE COMPILACIÓN

Para facilitar el proceso de compilación se ha creado un archivo "Makefile",
para ser usado por la utilidad "make" y asi realizar la compilación con un
solo comando.

Antes de proceder a la compilación, se debe editar en el archivo Makefile,
la variable "OS" y cambiar según corresponda al sistema operativo en el que
vaya a ser compilado el programa, las opciones son las siguientes:

MAC -> para plataformas OSX
WINDOWS -> para plataformas windows
LINUX -> para plataformas windows
CYGWIN -> para el emulador de bash en windows cygwin

Una vez realizada la modificación se puede proceder a compilar con la siguiente
orden desde la consola:

make

Si todo sale bien deberías tener tu ejecutable:

sudoku -> Para plataformas linux o mac
sudoku.exe -> Para windows o cygwin

## COMPILACIÓN MANUAL

En caso de querer realizar la compilación manualmente se debe correr la,
siguiente orden en consola:

gcc -DOS sudoku.c librerias/gnrlslib.c librerias/sudokulib.c librerias/printlib.c librerias/mistrlib.c -o sudoku

Reemplazando -DOS por -D(Sistema Operativo) sin el paréntesis, aceptando las,
siguientes opciones:

MAC -> para plataformas OSX
WINDOWS -> para plataformas windows
LINUX -> para plataformas windows
CYGWIN -> para el emulador de bash en windows cygwin

Con esto deberías obtener tu ejecutable.

## COMENTARIOS DE IMPLEMENTACION

Como los valores a ser almacenados en cada casilla del tablero pueden ser
valores en el rango de 1-9 tome la decision de en lugar de ocupar una matriz
de tipo int que permite valores 2^32 para enteros sin signo ocupar una matriz
unsigned char que me permite valores de 2^8 (256) lo cual es suficiente para
las necesidades de le juego, lo cual implica una optimización en el ahorro del
espacio requerido en memoria por utilizar variables que requieren de 1 byte en
lugar de variables que requieren de 4 bytes.

Es claro que tal ves para un juego como este el ahorro no se note y sea
insignificante por las dimensiones de mi arreglo, pero en otras escenarios
tal ves este tipo de optimizaciones puedan ayudar al programa.

## CREDITOS

Ramo: Fundamentos de Programación
Profesora: Francia Jimenez
Bibliografía: Introducción a la Programación en C (Andres Marzal - Isabel Gracia)
Alumno: Jesus Urrutia
