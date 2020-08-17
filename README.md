# SUDOKU - UN JUEGO DE LOGICA

El juego consiste en un tablero de 9x9, dividido en regiones de 3x3 llamados
cuadrantes. Cada casilla puede contener valores del 1-9 respetando las
siguientes reglas:

a) El valor debe ser unico en su fila
b) El valor debe ser unico en su columna
c) El valor debe ser unico en su cuadrante

## CONSIDERACIONES DE COMPILACION

El programa fue desarrollado principalmente en entorno MAC (OSX 10.7 - gcc 4.2)
donde se realizaron las ultimas pruebas de funcionamiento, a pesar de ello el
programa fue pensado para poder ser compilado en entornos unix (de preferencia)
y windows con opciones que se especifican en el apartado de "Instrucciones de
Compilacion". Aunque por la falta de pruebas en las demas plataformas
disponibles el programa pueda presentar algun error inesperado.

## INSTRUCCIONES DE COMPILACION

Para facilitar el proceso de compilacion se ha creado un archivo "Makefile",
para ser usado por la utilidad "make" y asi realizar la compilacion con un
solo comando.

Antes de proceder a la compilacion, se debe editar en el archivo Makefile,
la variable "OS" y cambiar segun corresponda al sistema operativo en el que
vaya a ser compilado el programa, las opciones son las siguientes:

MAC -> para plataformas OSX
WINDOWS -> para plataformas windows
LINUX -> para plataformas windows
CYGWIN -> para el emulador de bash en windows cygwin

Una vez realizada la modificacion se puede proceder a compilar con la siguiente
orden desde la consola:

make

Si todo sale bien deberias tener tu ejecutable:

sudoku -> Para plataformas linux o mac
sudoku.exe -> Para windows o cygwin

## COMPILACION MANUAL

En caso de querer realizar la compilacion manualmente se debe correr la,
siguiente orden en consola:

gcc -DOS sudoku.c librerias/gnrlslib.c librerias/sudokulib.c librerias/printlib.c librerias/mistrlib.c -o sudoku

Reemplazando -DOS por -D(Sistema Operativo) sin el parentesis, aceptando las,
siguientes opciones:

MAC -> para plataformas OSX
WINDOWS -> para plataformas windows
LINUX -> para plataformas windows
CYGWIN -> para el emulador de bash en windows cygwin

Con esto deberias obtener tu ejecutable.

## COMENTARIOS DE IMPLEMENTACION

Como los valores a ser almacenados en cada casilla del tablero pueden ser
valores en el rago de 1-9 tome la decision de en lugar de ocupar una matriz
de tipo int que permite valores 2^32 para enteros sin signo ocupar una matriz
unsigned char que me permite valores de 2^8 (256) lo cual es suficiente para
las necesidades de le juego, lo cual implica una optimizacion en el ahorro del
espacio requerido en memoria por utilizar varibles que requieren de 1 byte en
lugar de variables que requieren de 4 bytes.

Es claro que tal ves para un juego como este el ahorro no se note y sea
insignificante por las dimensiones de mi arreglo, pero en otras escenarios
tal ves este tipo de optimizaciones puedan ayudar al programa.

## CREDITOS

Ramo: Fundamentos de Programacion
Profesora: Francia Jimenez
Bibliografia: Introduccion a la Programacion en C (Andres Marzal - Isabel Gracia)
Alumno: Jesus Urrutia