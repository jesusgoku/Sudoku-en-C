#ifndef __PRINTLIB_H__
#define __PRINTLIB_H__

#include <stdio.h>
#include <stdlib.h>
#include "../librerias/mistrlib.h"

#ifndef CONSOLE_COLS
#define CONSOLE_COLS 80
#endif // CONSOLE_COLS

// Prototipos de Funciones
void instrucciones(); // Muestra las instrucciones
void print_repeat_char(char c, int n); // Imprime el caracter c repetido n veces
void print_center(char *c, int col); // Imprime la cadena apuntada por c centrada
void cls(); // Limpia la pantalla
void pausa(); // Crea una pausa en la ejecucion, esperando la accion del usuario
void clear(); // Limpia el buffer de entrada
void logo_sudoku(); // Muestra el logo del juego

#endif // __PRINTLIB_H__
