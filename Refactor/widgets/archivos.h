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
char *title = "Seleccione Archivo";
char *label = "VEREMOS";
char *button[] = { "OK", "CANCEL" };

char *path = "/../";
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
