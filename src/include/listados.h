/* 
 * File:   listados.h
 * Author: charlie
 *
 * Created on 15 de febrero de 2012, 19:01
 */

#ifndef _LISTADOS_H
#define	_LISTADOS_H
#include <cdk/cdk.h>
#include "callbacks.h"
CDKSCROLL *listado (CDKSCREEN * pantalla, char *tabla, char *columna);
void mostrar_referencias (CDKMATRIX * matriz, char *tabla, char *columna);
#ifdef	__cplusplus
extern "C"
{
#endif




#ifdef	__cplusplus
}
#endif

#endif				/* _LISTADOS_H */
