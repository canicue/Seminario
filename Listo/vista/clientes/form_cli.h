/* 
 * File:   form_cli.h
 * Author: canicue
 *
 * Created on 14 de enero de 2012, 13:41
 */

#ifndef _FORM_CLI_H
#define	_FORM_CLI_H

#include "../formularios.h"

CDKMATRIX *matrix_cli;
char *titulo;
#define  filas 6
#define columnas 1
#define vrows 6
#define  vcols  1
char *coltitle[10], *rowtitle[10], *mesg[10];
int colwidth[10], colvalue[10];
void form_cli(CDKSCREEN *cdkScreen);
#ifdef	__cplusplus
extern "C" {
#endif




#ifdef	__cplusplus
}
#endif

#endif	/* _FORM_CLI_H */

