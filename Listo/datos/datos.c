#include <stdio.h>

#include "datos.h"
sqlite3 *conectar(char* nombre)
{
    int err=0;
    sqlite3 *db;
    sqlite3_open(nombre,&db);
    printf("%d",err);
    return db;
;

}