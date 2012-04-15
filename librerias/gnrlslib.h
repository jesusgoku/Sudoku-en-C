#ifndef __GNRLSLIB_H
#define GNRLSLIB_H

#include <stdio.h>

#ifndef __CONSOLE_COLS__
#define __CONSOLE_COLS__
#define CONSOLE_COLS 80
#endif __CONSOLE_COLS__

/* Introdusco un nuevo tipo boolean y una enumeracion para dotar de claridad al
  codigo al momento de utilizar respuestas verdadero o falso
*/

#ifndef __BOOLEAN__
#define __BOOLEAN__
typedef enum { False = 0, True = 1 } boolean;
#endif __BOOLEAN__

#endif GNRLSLIB_H