/* 
 * File:   datos.h
 * Author: canicue
 *
 * Created on 14 de febrero de 2012, 23:48
 */

#ifndef _DATOS_H
#define	_DATOS_H
#include "consultas.h"
#include <sqlite3.h>
#define BASE "base.sqlite"
sqlite3 *conexion;
sqlite3 *conectar(char* nombre);
char *error;
void desconectar();
void buscar_registro(char *tabla,char *nombre,char *valor,void *callback,void *extra);
void borrar_registro(char *tabla,char *columna,char *valor);
void listar_registros(char *tabla,void* callback,void *extra);
void ver_tabla(char *nombre,int limite,char *visible);
#ifdef	__cplusplus
extern "C" {
#endif




#ifdef	__cplusplus
}
#endif

#endif	/* _DATOS_H */

