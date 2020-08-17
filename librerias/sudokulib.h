#ifndef __SUDOKULIB_H__
#define __SUDOKULIB_H__

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../librerias/gnrlslib.h"
#include "../librerias/mistrlib.h"

/* Las constantes siguientes representan
  N -> Dimensiones del tablero
  I -> Dimension de cada casilla para guardar meta informacion
*/
#define N 9
#define I 2

/* Para ahorrar espacio en las declaraciones se crea el tipo uchar que se
  corresponde con el tipo unsigned char el cual sera usado para almacenar los
  valores en nuestro tablero de sudoku.
*/
#ifndef __UCHAR__
#define __UCHAR__
typedef unsigned char uchar;
#endif // __UCHAR__

// Prototipo de Funciones
void llenar_tablero(uchar A[][N][I]); // Llena tablero de 0
void mostrar_matriz(uchar A[][N][I]); // Muestra matriz en bruto
void mostrar_tablero(uchar A[][N][I]); // Muestra matriz con formato
boolean val_error(uchar A[][N][I],uchar val, uchar f, uchar c); // Valida reglas
boolean val_error_msj(uchar A[][N][I],uchar val, uchar f, uchar c, uchar *msj); // Valida regla genera msj error
boolean error_fila(uchar A[][N][I],uchar val, uchar f); // Valida la fila
boolean error_columna(uchar A[][N][I],uchar val, uchar c); // Valida la columna
boolean error_cuadrante(uchar A[][N][I],uchar val, uchar f, uchar c); // Valida el cuadrante
boolean error_edicion(uchar A[][N][I], uchar f, uchar c); // Verifica si la casilla es editable
void fijar_valor(uchar A[][N][I],uchar val, uchar f, uchar c); // Fijar valor en una casilla
void sudoku_ini(uchar A[][N][I], uchar n); // Inicializa el tablero con n numeros iniciales
uchar pedir_valor(); // Pide un valor al usuario
uchar pedir_coord(uchar *msj); // Pide una coordena al usuario indicada por msj
uchar pedir_caracter(); // Pide un caracter al usuario
boolean tablero_lleno(uchar A[][N][I]); // Verifica si el tablero esta lleno
uchar pregunta_yn(const char *pregunta); // Pregunta al usuario, espera respuesta y/n

#endif // __SUDOKULIB_H__
