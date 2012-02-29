/* 
 * File:   persistencia.h
 * Author: charlie
 *
 * Created on 16 de febrero de 2012, 13:43
 */

#ifndef _PERSISTENCIA_H
#define	_PERSISTENCIA_H
#include <string.h>
#include <cdk/cdk.h>
#include <cdk/matrix.h>
int guardar_matriz (CDKMATRIX * matriz);
int modificar_matriz (CDKMATRIX * matriz);
int borrar_matriz (CDKMATRIX * matriz);
void tratar_error (CDKSCREEN * pantalla, char *tabla);
void arrepentimiento (CDKMATRIX * matriz, int elegido);

#ifdef	__cplusplus
extern "C"
{
#endif



#ifdef	__cplusplus
}
#endif

#endif				/* _PERSISTENCIA_H */
