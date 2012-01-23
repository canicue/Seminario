/* 
 * File:   form_prov.h
 * Author: canicue
 *
 * Created on 18 de enero de 2012, 18:01
 */

#ifndef _FORM_PROV_H
#define	_FORM_PROV_H

#include "../../controlador/formularios.h"

CDKMATRIX *matrix_prov;
char *titulo;
#define  filas 5
#define columnas 1
#define vrows 5
#define  vcols  1
char *coltitle[10], *rowtitle[10], *mesg[10];
int colwidth[10], colvalue[10];
void form_prov(CDKSCREEN *cdkScreen);
#ifdef	__cplusplus
extern "C" {
#endif




#ifdef	__cplusplus
}
#endif

#endif	/* _FORM_PROV_H */

