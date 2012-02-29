/* 
 * File:   callbacks.h
 * Author: charlie
 *
 * Created on 14 de febrero de 2012, 23:43
 */

#ifndef _CALLBACKS_H
#define	_CALLBACKS_H
#include <matrix.h>
#include <scroll.h>
#include <dialog.h>
int call_alta (void *nombre, int argc, char **argv, char **azColName);
int call_modificacion (void *nombre, int argc, char **argv, char **azColName);
int call_lista (void *nombre, int argc, char **argv, char **azColName);
int call_borrado (void *nombre, int argc, char **argv, char **azColName);
int call_cantidad (void *nombre, int argc, char **argv, char **azColName);
#define set_col(n, width, string) \
coltitle[n] = string;   colwidth[n] = width	//; colvalue[n] = vVIEWONLY //vUMIXED
#define set_readonly(n, width, string) \
coltitle[n] = string;   colwidth[n] = width ; colvalue[n] = vVIEWONLY

#define set_row(n, string) \
   rowtitle[n] = "</B/6>" string


CDKMATRIX *matriz;
CDKSCROLL *lista_scroll;
CDKDIALOG *dialogo;


#ifdef	__cplusplus
extern "C"
{
#endif




#ifdef	__cplusplus
}
#endif

#endif				/* _CALLBACKS_H */
