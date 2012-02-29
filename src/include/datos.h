/* 
 * File:   datos.h
 * Author: charlie
 *
 * Created on 14 de febrero de 2012, 23:48
 */
#ifndef _DATOS_H
#define	_DATOS_H
#include "consultas.h"
#include <sqlite3.h>

#define BASE "base_3.sqlite"
//#define BASE "base.sqlite"
sqlite3 *conexion;
sqlite3 *conectar (char *nombre);
char *error;
void desconectar ();
void buscar_registro (char *tabla, char *nombre, char *valor, void *callback,
		      void *extra);
int borrar_registro (char *tabla, char *columna, char *valor, void *callback);
int modificar_registro (char *tabla, char **columnas, char *identificador,
			char *valor, char **nuevos, int nro);
void listar_registros (char *tabla, void *callback, void *extra);
//void ver_tabla(char *nombre,int limite,char *visible);
void ver_tabla (char *nombre, int limite, char *visible, void *callback,
		void *extra);
int guardar_cosa (char *tabla, char **columnas, char **valores, int nro);
int buscar_ultimo (char *tabla, char *nombre, void *callback);
int ultimo_id (char *tabla, char *nombre);
#ifdef	__cplusplus
extern "C"
{
#endif




#ifdef	__cplusplus
}
#endif

#endif				/* _DATOS_H */
