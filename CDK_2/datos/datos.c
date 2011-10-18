#include <stddef.h>
#include <stdio.h>

#include "datos.h"
sqlite3 *conectar(char *nombre)
{
 
    sqlite3 *conexion=NULL;
    sqlite3_open(nombre,&conexion);
    printf("hola");
    return conexion;

}