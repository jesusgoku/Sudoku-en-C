#ifndef __MISTRLIB_H__
#define __MISTRLIB_H__

#include <stdio.h>
#include "../librerias/gnrlslib.h"

// Prototipo de Funciones
int mistrlen(char *c); // Devuelve el largo de la cadena
void mistrcpy(char *dest, const char *src); // Copia la cadena src en dest
char chrtonum(const char n); // Convierte el caracter n en el numero n

#endif // __MISTRLIB_H__
