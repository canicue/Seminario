/* 
 * File:   archivos.h
 * Author: charlie
 *
 * Created on 17 de febrero de 2012, 23:07
 */

#ifndef _ARCHIVOS_H
#define	_ARCHIVOS_H
#include <cdk/cdk.h>
#include <cdk/fselect.h>
#include<cdk/viewer.h>
#include<cdk/matrix.h>
CDKFSELECT *selector;

//char *labela = "VEREMOS";

char **contenido;
int lineas;
char titulo_archivo[256];
CDKVIEWER *visor_archivo;
CDKFSELECT *seleccionar_archivo ();
CDKVIEWER *ver_archivo ();
void elegir_archivo(CDKMATRIX *matriz);
#ifdef	__cplusplus
extern "C"
{
#endif




#ifdef	__cplusplus
}
#endif

#endif				/* _ARCHIVOS_H */
