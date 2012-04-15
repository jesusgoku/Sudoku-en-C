#ifndef __SUDOKULIB_C__
#define __SUDOKULIB_C__

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../librerias/gnrlslib.h"
#include "../librerias/mistrlib.h"

/* Para ahorrar espacio en las declaraciones se crea el tipo uchar que se
  corresponde con el tipo unsigned char el cual sera usado para almacenar los
  valores en nuestro tablero de sudoku.
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
#endif __UCHAR__

// Prototipo de Funciones
void llenar_tablero(uchar A[][N][I]);
void mostrar_matriz(uchar A[][N][I]);
void mostrar_tablero(uchar A[][N][I]);
boolean val_error(uchar A[][N][I],uchar val, uchar f, uchar c);
boolean val_error_msj(uchar A[][N][I],uchar val, uchar f, uchar c, uchar *msj);
boolean error_fila(uchar A[][N][I],uchar val, uchar f);
boolean error_columna(uchar A[][N][I],uchar val, uchar c);
boolean error_cuadrante(uchar A[][N][I],uchar val, uchar f, uchar c);
boolean error_edicion(uchar A[][N][I], uchar f, uchar c);
void fijar_valor(uchar A[][N][I],uchar val, uchar f, uchar c);
void sudoku_ini(uchar A[][N][I], uchar n);
uchar pedir_valor();
uchar pedir_coord(uchar *msj);
uchar pedir_caracter();
boolean tablero_lleno(uchar A[][N][I]);
uchar pregunta_yn(const char *pregunta);

// Cuerpo de Funciones
void llenar_tablero(uchar A[][N][I]){
    /* Inicializa el tablero a 0
      
      Argumentos:
      uchar A[][N][I] -> Matriz del tablero
     
    */
    uchar i = 0, j = 0, k = 0;
    for(i = 0;i < N;i++) for(j = 0;j < N;j++) for(k = 0;k < I;k++) A[i][j][k] = 0;
}

void mostrar_matriz(uchar A[][N][I]){
    /* Muestra la matriz por pantalla
      
      Argumetos:
      uchar A[][N][I] -> Matriz del tablero
     
    */
    uchar i = 0, j = 0;
    for(i = 0;i < N;i++){
        for(j = 0;j < N;j++){
            printf("%hhd ",A[i][j][0]);
        }
        printf("\n");
    }
}


void mostrar_tablero(uchar A[][N][I]){
    /* Muestra el tablero de sudoku con formato
      
      Argumentos:
      uchar A[][N][I] -> Matriz del tablero
     
    */
    uchar i = 0, j = 0, k = 0;
    for(i = 0;i < N;i++){
        // Imprimo los numeros de las columas
        if(i == 0){
            printf("  | ");
            for(k = 0;k < N;k++){
                printf("%hhd ",k);
                if(k == 2 || k == 5 || k == 8) printf("| ");
            }
            printf("\n");
        }
        // Imprimo las lineas divisorias horizontales
        if(i == 0 || i == 3 || i == 6){
            for(k = 0;k < 14;k++) printf("- ");
            printf("\n");
        }
        for(j = 0;j < N;j++){
            // Imprimo los numeros de filas
            if(j == 0) printf("%hhd ",i);
            // Imprimo las lineas divisorias verticales
            if(j == 0 || j == 3 || j == 6) printf("| ");
            // Imprimo el numero de celda
            printf("%hhd ",A[i][j][0]);
            // Imprimo la ultima linea divisoria vertical
            if(j == 8) printf("|");
        }
        // Imprimo la ultima linea divisoria horizontal
        if(i == 8){ printf("\n"); for(k = 0;k < 14;k++) printf("- "); }
        printf("\n");
    }
}

boolean val_error(uchar A[][N][I], uchar val, uchar f, uchar c){
    /* Verifica que el valor cumpla las reglas del juego
      
      Argumentos:
      uchar A[][N][I] -> Matriz del tablero
      uchar val -> valor a comprobar
      uchar f -> fila de comprobacion
      uchar c -> columna de comprobacion
      
      Retorno:
      True -> Si hay error
      False -> Si no inflinge las reglas
     
    */
    uchar i = 0, j = 0;
    uchar fini = 0, cini = 0;
    // Primero recorro la fila y la columna
    for(i = 0;i < N;i++){
        // Recorro la fila
        if(A[i][c][0] == val){
            return True;
        }
        // Recorro la columna
        if(A[f][i][0] == val){
            return True;
        }
    }
    // Ahora analizamos el cuadrante
    fini = f - (f % 3);
    cini = c - (c % 3);
    for(i = fini;i < (fini + 3);i++){
        for(j = cini;j < (cini + 3);j++){
            if(A[i][j][0] == val){
                return True;
            }
        }
    }
    return False;
}

boolean val_error_msj(uchar A[][N][I], uchar val, uchar f, uchar c, uchar *msj){
    /* Verifica que se cumplan las reglas del juego y genera un msj
      
      Argumentos:
      uchar A[][N][I] -> Matriz del tablero
      uchar val -> Valor a comprobar
      uchar f -> Fila de comprobacion
      uchar c -> Columna de comprobacion
      uchar *msj -> Puntero a donde se copiara el mensaje de error
      
      Retorno:
      True -> Si hay error
      False -> Si no inflinge las reglas
     
    */
    uchar i = 0, j = 0;
    uchar fini = 0, cini = 0;
    // Verifico que no sea celda inicial
    if(A[f][c][1] == 1){
        mistrcpy(msj,"Error, celda no editable");
        return True;
    }
    // Recorro la fila y la columna
    for(i = 0;i < N;i++){
        // Recorro la fila
        if(A[f][i][0] == val){
            //mistrcpy(msj,"Error, coicidencia fila");
            sprintf(msj,"Error, coincidencia fila [%hhd,%hhd]",f,i);
            return True;
        }
        // Recorro la columna
        if(A[i][c][0] == val){
            //mistrcpy(msj,"Error, coincidencia columna");
            sprintf(msj,"Error, coincidencia columna [%hhd,%hhd]",i,c);
            return True;
        }
    }
    // Ahora analizamos el cuadrante
    fini = f - (f % 3);
    cini = c - (c % 3);
    for(i = fini;i < (fini + 3);i++){
        for(j = cini;j < (cini + 3);j++){
            if(A[i][j][0] == val){
                //mistrcpy(msj,"Error, coincidencia cuadrante");
                sprintf(msj,"Error, coicidencia cuadrante [%hhd,%hhd]",i,j);
                return True;
            }
        }
    }
    return False;
}

boolean error_fila(uchar A[][N][I],uchar val, uchar f){
    /* Verifica que el valor val no se repita en la fila f
      
      Argumentos:
      uchar A[][N][I] -> Matriz del tablero
      uchar val -> Valor a comprobar
      uchar f -> Fila a ser comprobada
      
      Retorno:
      True -> Si hay error
      False -> Si todo ha ido bien
     
    */
    uchar i = 0;
    for(i = 0;i < N;i++) if(A[f][i][0] == val) return True;
    return False;
}

boolean error_columna(uchar A[][N][I],uchar val, uchar c){
    /* Verifica que el valor val no se repita en la columna c
      
      Argumentos:
      uchar A[][N][I] -> Matriz del tablero
      uchar val -> Valor a comprobar
      uchar c -> Columna a ser comprobada
      
      Retorno:
      True -> si hay error
      False -> si todo ha ido bien
     
    */
    uchar i = 0;
    for(i = 0;i < N;i++) if(A[i][c][0] == val) return True;
    return False;
}

boolean error_cuadrante(uchar A[][N][I],uchar val, uchar f, uchar c){
    /* Verifica que el valor val no se repita en el cuadrante
      
      Argumentos:
      uchar A[][N][I] -> Matriz del tablero
      uchar val -> Valor a comprobar
      uchar f -> Fila en donde se quiere comprobar
      uchar c -> Columna en donde se quiere comprobar
      
      Retorno:
      True -> Hay error
      False -> No hay error
     
    */
    uchar i = 0, j = 0;
    uchar fini = 0, cini = 0;
    fini = f - (f % 3);
    cini = c - (c % 3);
    for(i = fini;i < (fini + 3);i++){
        for(j = cini;j < (cini + 3);j++){
            if(A[i][j][0] == val){
                return True;
            }
        }
    }
    return False;
}

boolean error_edicion(uchar A[][N][I], uchar f, uchar c){
    /* Verifica que una casilla del tablero sea editable
      
      Argumentos:
      uchar A[][N][I] -> Matriz del tablero
      uchar f -> Fila de la casilla
      uchar -> Columna de la casilla
      
      Retorno:
      True -> Hay Error (No es editable)
      False -> No hay error (Es editable)
     
    */
    return A[f][c][1] ? True : False;
}

void fijar_valor(uchar A[][N][I],uchar val, uchar f, uchar c){
    /* Guarda el valor en la casilla
      
      Argumentos:
      uchar A[][N][I] -> Matriz del tablero
      uchar val -> Valor a guardar
      uchar f -> Fila en donde se guardara
      uchar c -> Columna en donde se guardara
     
    */
    A[f][c][0] = val;
}

void sudoku_ini(uchar A[][N][I], uchar n){
    /* Inicializa en tablero de sudoku con n valores iniciales (1 <= n <= 17)
      
      Argumentos:
      uchar A[][N][I] -> Matriz del tablero
      uchar n -> Numero de valores iniciales (1 <= n <= 17)
     
    */
    uchar i = 0,f = 0, c  = 0, val = 0, contador = 0;
    srand(time(NULL));
    n = n >= 1 && n <= 17 ? n : 4;
    while(contador < n){
        f = rand() % 9;
        c = rand() % 9;
        val = 1 + (rand() % 9);
        if(A[f][c][0] == 0){
            if(!val_error(A,val,f,c)){
                A[f][c][0] = val;
                A[f][c][1] = 1;
                contador++;
            }
        }
    }
}

uchar pedir_valor(){
    /* Pide un valor al usuario en 0 y 9
      
      Retorno:
      El valor ingresado por el usuario
     
    */
    unsigned int valor = 0;
    while(True){
        printf("\nDame un valor (0-9): ");
        clear();
        scanf("%u",&valor);
        if(valor <= 9) break;
        else printf("\nError, valor no valido, intentalo nuevamente.");
    }
    return (uchar) valor;
}

uchar pedir_coord(uchar *msj){
    /* Pide una coordenada al usuario
      
      Argumentos:
      uchar *msj -> Intrucciones para el valor a ingresar
      
      Retorno:
      Coordenada ingresada por el usuario
     
    */
    uchar coord;
    while(True){
        printf("%s",msj);
        clear();
        scanf("%c",&coord);
        coord = chrtonum(coord);
        if(coord <= 8) break;
        else printf("Error, coordenada no valida, intetanlo nuevamente.\n");
    }
    return coord;
}

uchar pedir_caracter(){
    /* Pide un caracter al usuario
      
      Retorno:
      El caracter ingresado por el usuario
     
    */
    uchar caracter = 0;
    printf("\nIngrese valor(0-9) o (s)alir o (r)einiciar: ");
    clear();
    caracter = getchar();
    clear();
    return caracter;
}

boolean tablero_lleno(uchar A[][N][I]){
    /* Verifica si el tablero esta lleno
      
      Argumentos:
      uchar A[][N][I] -> tablero de sudoku
      
      Retorno:
      True -> El tablero esta lleno
      False -> El tablero aun no esta lleno
     
    */
    uchar i = 0, j = 0;
    for(i = 0;i < N;i++)
        for(j = 0;j < N;j++)
            if(A[i][j][0] == 0)
                return False;
    return True;
}

uchar pregunta_yn(const char *pregunta){
    /* Pregunta al usuario pregunta esperando y/n
      
      Argumentos:
      const char *pregunta -> Pregunta a ser respondida por el usuario
     
     Retorno:
     Respuesta del usuario
     
    */
    uchar respuesta;
    while(True){
        printf("%s (y/n): ", pregunta);
        clear();
        scanf("%c", &respuesta);
        if(respuesta == 'y' || respuesta == 'n') break;
        else printf("Error, respuesta incorrecta.\n");
    }
    return respuesta;
}

#endif __SUDOKULIB_C__