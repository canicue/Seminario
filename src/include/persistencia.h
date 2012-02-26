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
int guardar_cliente (CDKMATRIX * matriz);
int guardar_tecnico (CDKMATRIX * matriz);
int guardar_proveedor (CDKMATRIX * matriz);
int guardar_insumo (CDKMATRIX * matriz);
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
