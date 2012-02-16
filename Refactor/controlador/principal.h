/* 
 * File:   principal.h
 * Author: canicue
 *
 * Created on 14 de febrero de 2012, 18:59
 */

#ifndef _PRINCIPAL_H
#define	_PRINCIPAL_H
#include <string.h>
#include <cdk.h>
void login ();
char *pedir_datos (char *tipo);
void entrada ();
void error_login ();
void area_tecnica ();
void menu_administrativa ();
void menu_tecnica ();
void area_administrativa ();


static int entryCB (EObjectType cdktype GCC_UNUSED,
		    void *object GCC_UNUSED, void *clientData, chtype key);
#ifdef	__cplusplus
extern "C"
{
#endif




#ifdef	__cplusplus
}
#endif

#endif				/* _PRINCIPAL_H */
