/* 
 * File:   formularios.h
 * Author: charlie
 *
 * Created on 14 de febrero de 2012, 23:39
 */

#ifndef _FORMULARIOS_H
#define	_FORMULARIOS_H
#include <cdk/cdk.h>
#include "../datos/datos.h"
#include "../controlador/callbacks.h"

#define  vcols  1

int filas;
int columnas;
int vrows;
char *coltitle[10], *rowtitle[10], *mesg[10];
int colwidth[10], colvalue[10];

CDKMATRIX *formulario_alta (char *tabla, char *identificador, PROCESSFN prep,
			    PROCESSFN post);
CDKMATRIX *formulario_modificacion (char *tabla, char *columna, char *valor,
				    PROCESSFN prep, PROCESSFN post);

int driver_formulario (EObjectType cdktype GCC_UNUSED,
		       void *object GCC_UNUSED,
		       void *clientData, chtype input);
char *validar_formulario (CDKMATRIX * matriz);
void validar (CDKMATRIX * matriz);
#ifdef	__cplusplus
extern "C"
{
#endif




#ifdef	__cplusplus
}
#endif

#endif				/* _FORMULARIOS_H */
