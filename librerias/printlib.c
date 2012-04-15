#ifndef __PRINTLIB_C__
#define __PRINTLIB_C__

#include <stdio.h>
#include <stdlib.h>
#include "../librerias/mistrlib.h"

#ifndef CONSOLE_COLS
#define CONSOLE_COLS 80
#endif CONSOLE_COLS

// Prototipos de Funciones
void instrucciones();
void print_repeat_char(char c, int n);
void print_center(char *c, int col);
void cls();
void pausa();
void clear();
void logo_sudoku();

// Cuerpo de Funciones
void instrucciones(){
    cls();
    print_repeat_char('=',CONSOLE_COLS);
    printf("\n");
    print_center("SODOKU",CONSOLE_COLS);
    printf("\n");
    print_repeat_char('=',CONSOLE_COLS);
    printf("\n");
    printf("1.- El juego es un tablero de 9x9 celdas\n");
    printf("2.- A su ves dividido en regiones de 3x3 celdas llamados cuadrantes\n");
    printf("3.- En los cuales deben ir valores 1-9\n");
    printf("4.- Siguiendo las siguientes reglas:\n");
    printf("\n");
    printf("\ta) El numero debe ser unico en su fila\n");
    printf("\tb) El numero debe ser unico en su columna\n");
    printf("\tc) El numero debe ser unico en su cuadrante\n");
    printf("\n");
    printf("5.- Las coordenas van del 0-8 tanto para filas como columnas\n");
    printf("6.- Para borrar una casilla ingresa como valor 0\n");
    printf("7.- Para salir ingresa como valor s\n");
    printf("8.- Para reiniciar la partida ingresa como valor r\n");
    pausa();
}

void print_repeat_char(char c,int n){
    /* Imprime un caracter c repetido n veces
     
     Argumentos:
     char c -> Caracter que se quiere repetir
     char n -> Numero de veces que se repetica el caracter
    */
    int i = 0;
    for(i = 0;i < n;i++) printf("%c",c);
}

void print_center(char *c, int col){
    /* Imprime una cadena centrada en una columna de ancho col
      
      Argumentos:
      char *c -> puntero a la cadena que se centrara
      int col -> Ancho de la columna en la que se desea centrar
     
    */
    int len,i,colini;
    len = mistrlen(c) / 2;
    colini = (col / 2) - len;
    for(i=0;i < colini;i++) printf(" ");
    printf("%s",c);
    for(i=0;i < colini;i++) printf(" ");
}

void pausa(){
    /* Introduce una pausa en la ejecucion esperando la respuesta del usuario
     
    */
    printf("\nPresione enter para continuar...");
    clear();
    getchar();
}

/* En el siguiente trozo de programa se definen dos funciones que tienden a
  dar problemas en distintas plataformas, por eso se ha optado por una
  compilacion condicional esperando una orden pasada por medio del gcc con el
  comando -DETIQUETA
  
  Las funciones son las siguientes:
  
  cls: Realiza una limpieza de la pantalla
  clear: Limpiar el buffer de entrada
 
*/

#ifdef MAC

void cls(){ system("clear"); }
void clear(){ fpurge(stdin); }

#elif defined(LINUX)

void cls(){ system("clear"); }
void clear(){ __fpurge(stdin); }

#elif defined(WINDOWS)

void cls(){ system("cls"); }
void clear(){ fflush(stdin); }

#elif defined(CYGWIN)

void cls(){ int i = 0; for(i = 0;i < CONSOLE_COLS;i++) printf("\n"); }
void clear(){ fpurge(stdin); }

#else
    #error "Sistema Operativo Incorrecto"
#endif

void logo_sudoku(){
    cls();
    printf("                                           ,----..          ,--.               \n");
    printf("  .--.--.                     ,---,       /   /   \\     ,--/  /|               \n");
    printf(" /  /    '.          ,--,   .'  .' `\\    /   .     : ,---,': / '         ,--,  \n");
    printf("|  :  /`. /        ,'_ /| ,---.'     \\  .   /   ;.  \\:   : '/ /        ,'_ /|  \n");
    printf(";  |  |--`    .--. |  | : |   |  .`\\  |.   ;   /  ` ;|   '   ,    .--. |  | :  \n");
    printf("|  :  ;_    ,'_ /| :  . | :   : |  '  |;   |  ; \\ ; |'   |  /   ,'_ /| :  . |  \n");
    printf(" \\  \\    `. |  ' | |  . . |   ' '  ;  :|   :  | ; | '|   ;  ;   |  ' | |  . .  \n");
    printf("  `----.   \\|  | ' |  | | '   | ;  .  |.   |  ' ' ' ::   '   \\  |  | ' |  | |  \n");
    printf("  __ \\  \\  |:  | | :  ' ; |   | :  |  ''   ;  \\; /  ||   |    ' :  | | :  ' ;  \n");
    printf(" /  /`--'  /|  ; ' |  | ' '   : | /  ;  \\   \\  ',  / '   : |.  \\|  ; ' |  | '  \n");
    printf("'--'.     / :  | : ;  ; | |   | '` ,/    ;   :    /  |   | '_\\.':  | : ;  ; |  \n");
    printf("  `--'---'  '  :  `--'   \\;   :  .'       \\   \\ .'   '   : |    '  :  `--'   \\ \n");
    printf("            :  ,      .-./|   ,.'          `---`     ;   |,'    :  ,      .-./ \n");
    printf("             `--`----'    '---'        by            '---'       `--`----'     \n");
    printf("\n\n");
    print_center("..:: JESUSGOKU ::..",CONSOLE_COLS);
    pausa();
}

#endif __PRINTLIB_C__