/*
 * File:   formularios.h
 * Author: canicue
 *
 * Created on 18 de enero de 2012, 18:22
 */

#ifndef _FORMULARIOS_H
#define	_FORMULARIOS_H
#include  <cdk/cdk.h>
#include "../datos/datos.h"
#define set_col(n, width, string) \
coltitle[n] = string;   colwidth[n] = width ; colvalue[n] = vUMIXED
#define set_row(n, string) \
   rowtitle[n] = "</B/6>" string
#define  vcols  1

CDKMATRIX *matriz;
int filas;
int columnas ;
int vrows ;
char *coltitle[10], *rowtitle[10], *mesg[10];
int colwidth[10], colvalue[10];

//void ver_columnas(char *tabla);

void ver_tabla(char *nombre);



#ifdef	__cplusplus
extern "C" {
#endif




#ifdef	__cplusplus
}
#endif

#endif	/* _FORMULARIOS_H */

