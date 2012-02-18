/* 
 * File:   archivos.h
 * Author: canicue
 *
 * Created on 17 de febrero de 2012, 23:07
 */

#ifndef _ARCHIVOS_H
#define	_ARCHIVOS_H
#include <fselect.h>
#include<viewer.h>
CDKFSELECT *selector;

//char *labela = "VEREMOS";

char **contenido;

int lineas;
char titulo_archivo[256];
CDKVIEWER *visor_archivo;
CDKFSELECT *seleccionar_archivo ();
CDKVIEWER *ver_archivo ();
#ifdef	__cplusplus
extern "C"
{
#endif




#ifdef	__cplusplus
}
#endif

#endif				/* _ARCHIVOS_H */
