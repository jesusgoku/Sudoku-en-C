/******************************************************************************
 * Programa: Sudoku
 * Programador: Jesus Urrutia (16.073.876-6)
 * Ramo: Fundamentos de Programacion
 * Profesora: Francia Jimenez
 * Comentarios:
 * Si bien los numeros del tablero de sudoku son numeros enteros, estos son
 * numeros enteros entre el rango 1-9 con lo cual una variable int hubiera sido
 * inecesaria ya que no se requiete de 4 bytes para almacenar numeros en ese
 * rango, por eso tome la decision de utilizar un arreglo de unsigned char
 * que tienen un tamano de 1 byte permitiendome almacenar numeros en el rango
 * que necesitaba y me sobraba, lo que al final significa un importante ahorro
 * de memoria, tal vez al nivel de este programa no sea significativo ya que el
 * arreglo no es relativamente grande y las computadoras de hoy en dia poseen
 * suficiente memoria ram, pero me parecio bien introducir esta optimizacion.
 *****************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "librerias/gnrlslib.h"
#include "librerias/mistrlib.h"
#include "librerias/printlib.h"
#include "librerias/sudokulib.h"

int main (){
    uchar tablero[N][N][I]; // Tablero de Sudoku
    uchar valor = 0, fila = 0, columna = 0; // Variables
    uchar mensaje[100]; // Para almacenar y mostrar mensajes de estado
    
    logo_sudoku(); // Mostramos el logo del juego
    
    llenar_tablero(tablero); // Inicializamos la matriz a una matriz nula
    sudoku_ini(tablero,4); // Inicializamos el tablero con 4 valores
    instrucciones(); // Mostramos las instrucciones
    
    // Comienza el Juego
    while(True){
        cls(); // Limpiamos la pantalla
        mostrar_tablero(tablero); // Mostramos el tablero al usuario
        valor = pedir_caracter(); // Solicitamos un valor
        if(valor == 's') break; // Respuesta para salir, rompemos el ciclo
        else if(valor == 'r'){ // Respuesta para reiniciar
            llenar_tablero(tablero);
            sudoku_ini(tablero,4);
        }else if(valor >= '0' && valor <= '9'){ // Respuesta para ingresar valor
            valor = chrtonum(valor); // Convertimos el caracter en numero
            fila = pedir_coord("Dame la fila: "); // Solicitamos fila
            columna = pedir_coord("Dame la columna: "); // solicitamos columna
            if(!error_edicion(tablero,fila,columna)){ // Verificamos que sea una casilla editable
                if(valor == 0) fijar_valor(tablero,valor,fila,columna); // Si valor igual a 0 (Borrar casilla) fijamos el valor
                else{
                    if(!val_error_msj(tablero,valor,fila,columna,mensaje)){
                        fijar_valor(tablero,valor,fila,columna); // Verificamos las reglas, si cumple fijamos
                        if(tablero_lleno(tablero)){ // Verifico si completo el juego
                            printf("Felicidades! haz completado el juego!\n");
                            valor = pregunta_yn("Desea comenzar otra partida?");
                            if(valor == 'y'){ // Si responde afimativamente, reinicio el tablero
                                llenar_tablero(tablero);
                                sudoku_ini(tablero,4);
                            }else break; // De lo contrario salgo
                        }
                    }else{
                        printf("\n%s",mensaje); // Mostramos el error si es que lo hay
                        pausa(); // Introduce una pausa a la ejecucion
                    }
                }
            }else{
                printf("\nError, casilla no editable"); // Mostramos el error si es que lo hay
                pausa(); // Introduce una pausa a la ejecucion
            }
        }else{
            printf("\nError, opcion no valida"); // Mostramos el error si es que lo hay
            pausa(); // Introduce una pausa a la ejecucion
        }
    }
    
    return 0;
}