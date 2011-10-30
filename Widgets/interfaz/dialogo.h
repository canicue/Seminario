/* 
 * File:   dialogo.h
 * Author: canicue
 *
 * Created on 29 de octubre de 2011, 22:35
 */

#ifndef _DIALOGO_H
#define	_DIALOGO_H
#include <cdk/dialog.h>


CDKDIALOG *crear_dialogo(CDKSCREEN *cdkScreen,char **contenido);
void mostrar_dialogo();
#ifdef	__cplusplus
extern "C" {
#endif




#ifdef	__cplusplus
}
#endif

#endif	/* _DIALOGO_H */

