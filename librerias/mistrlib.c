#ifndef __MISTRLIB_C__
#define __MISTRLIB_C__

#include <stdio.h>
#include "../librerias/gnrlslib.h"

// Prototipo de Funciones
int mistrlen(char *c);
void mistrcpy(char *dest, const char *src);
char chrtonum(const char n);

// Cuerpo de Funciones
int mistrlen(char *c){
    /* Retorna el largo de la cadena apuntada por c

      Argumentos:
      char *c -> Puntero a la cadena que se le obtendra el largo

    */
    int i;
    for(i = 0;*(c+i) != '\0';i++);
    return i;
}

void mistrcpy(char *dest, const char *src){
    /* Copia la cadena apuntada por src a la cadena apuntada por dest

      Argumentos:
      char *dest -> Cadena de destino de la copia
      const char *src -> Cadena a ser copiada

    */
    int i = 0;
    while(*(src+i) != '\0'){
        *(dest+i) = *(src+i);
        i++;
    }
    *(dest+i) = '\0';
}

char chrtonum(const char n){
    /* Si el caracter es un numero lo devuelve como numero, si no el mismo caracter

     Argumentos:
     const char n -> Caracter numero
    */
    return (n >= '0' && n <= '9') ? n - '0' : n;
}

#endif // __MISTRLIB_C__
