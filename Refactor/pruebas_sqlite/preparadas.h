#ifndef PREPARADAS_H
#include <stdio.h>
#include <sqlite3.h>
#define BASE "personas.sqlite"
#define SQL_REGISTROS "SELECT * from persona where=?<? "
//#define *BASE="personas.sqlite";
char *error;
int rc;
sqlite3 *conexion;
sqlite3_stmt *consulta;
sqlite3 *conectar(char *base);
void leer_registros(char *base,char *tabla);
void llenar_tabla(char *nombre);
char *leer_palabra(char *path);

#define PREPARADAS_H 
#endif
