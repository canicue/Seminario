/* 
 * File:   utils.h
 * Author: charlie
 *
 * Created on 20 de febrero de 2012, 11:07
 */

#ifndef _UTILS_H
#define	_UTILS_H
#include <string.h>
#include "datos.h"

char *ultimo;
char *generar_id (char *prefijo, char *tabla, char *columna);
void setear_id (CDKMATRIX * matriz);
void armar_prefijo (char *nombre, char *destino);
#ifdef	__cplusplus
extern "C"
{
#endif




#ifdef	__cplusplus
}
#endif

#endif				/* _UTILS_H */
