/* 
 * File:   persistencia.h
 * Author: canicue
 *
 * Created on 16 de febrero de 2012, 13:43
 */

#ifndef _PERSISTENCIA_H
#define	_PERSISTENCIA_H
#include <string.h>
#include <cdk.h>
int guardar_matriz (CDKMATRIX * matriz);
int guardar_cliente (CDKMATRIX * matriz);
int guardar_tecnico (CDKMATRIX * matriz);
int guardar_proveedor (CDKMATRIX * matriz);
int guardar_insumo (CDKMATRIX * matriz);

#ifdef	__cplusplus
extern "C"
{
#endif



#ifdef	__cplusplus
}
#endif

#endif				/* _PERSISTENCIA_H */
