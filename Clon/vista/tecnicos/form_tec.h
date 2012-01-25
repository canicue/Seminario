/* 
 * File:   form_tec.h
 * Author: canicue
 *
 * Created on 14 de enero de 2012, 13:41
 */

#ifndef _FORM_TEC_H
#define	_FORM_TEC_H

#include "../../controlador/formularios.h"

CDKMATRIX *matrix_tec;
char *titulo;
#define  filas 5
#define columnas 1
//#define vrows 5
#define  vcols  1
char *coltitle[10], *rowtitle[10], *mesg[10];
int colwidth[10], colvalue[10];
void form_tec(CDKSCREEN *cdkScreen);
#ifdef	__cplusplus
extern "C" {
#endif




#ifdef	__cplusplus
}
#endif

#endif	/* _FORM_TEC_H */

