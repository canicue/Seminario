/* 
 * File:   datos.h
 * Author: canicue
 *
 * Created on 14 de octubre de 2011, 18:11
 */

#ifndef _DATOS_H
#define	_DATOS_H
#include <sqlite3.h>
#define BASE "base.sqlite"
sqlite3 *conectar(char* nombre);

#ifdef	__cplusplus
extern "C" {
#endif




#ifdef	__cplusplus
}
#endif

#endif	/* _DATOS_H */

