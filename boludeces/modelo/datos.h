#ifndef DATOS_H
#define DATOS_
#include <sqlite3.h>
#include <string.h>
#include "configuracion.h"
typedef struct
{
char* nombre;
char* tipo;

} columna;
sqlite3 *base ;
sqlite3_stmt *stm ;
int estado;
void conectar(char *base);
void desconectar();
int crear_tabla(columna** columnas);
columna** pedir_datos();


#endif

