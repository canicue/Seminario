/* 
 * File:   callbacks.h
 * Author: canicue
 *
 * Created on 23 de enero de 2012, 13:22
 */

#ifndef _CALLBACKS_H
#define	_CALLBACKS_H
#include <cdk/matrix.h>
#include <cdk/alphalist.h>
#include "../datos/datos.h"
#define set_col(n, width, string) \
coltitle[n] = string;   colwidth[n] = width ; colvalue[n] = vMIXED
#define set_row(n, string) \
   rowtitle[n] = "</B/6>" string
#define  vcols  1
CDKMATRIX *matriz;
CDKALPHALIST *listado;
int callback_reg(void *NotUsed, int argc, char **argv, char **azColName);
int call_columnas(void *NotUsed, int argc, char **argv, char **azColName);
int call_tabla(void *nombre, int argc, char **argv, char **azColName);
int callback_registro(void *nombre, int argc, char **argv, char **azColName);
int callback_lista(void *nombre, int argc, char **argv, char **azColName);

#ifdef	__cplusplus
extern "C" {
#endif




#ifdef	__cplusplus
}
#endif

#endif	/* _CALLBACKS_H */

