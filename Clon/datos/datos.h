/* 
 * File:   datos.h
 * Author: canicue
 *
 * Created on 14 de octubre de 2011, 18:11
 */

#ifndef _DATOS_H
#define	_DATOS_H
#ifndef _CONSULTAS_H
#include "consultas.h"
#endif
#include <sqlite3.h>
#define BASE "base.sqlite"
static sqlite3 *conexion;
sqlite3 *conectar(char* nombre);
char *error;
void desconectar();
void buscar_registro(char *tabla,char *nombre,char *valor,void *callback,void *extra);
void borrar_registro(char *tabla,char *id);
static int callback(void *NotUsed, int argc, char **argv, char **azColName);

#ifdef	__cplusplus
extern "C" {
#endif




#ifdef	__cplusplus
}
#endif

#endif	/* _DATOS_H */

