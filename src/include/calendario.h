/* 
 * File:   calendario.h
 * Author: canicue
 *
 * Created on 22 de febrero de 2012, 10:23
 */

#ifndef _CALENDARIO_H
#define	_CALENDARIO_H
#include<cdk/cdk.h>
//#include <cdkscreen.h>
#include <cdk/calendar.h>
CDKCALENDAR *calendario (CDKSCREEN * pantalla);

void mostrar_calendario(CDKMATRIX *matriz,CDKCALENDAR *calendario);
CDKCALENDAR *calendar;
#ifdef	__cplusplus
extern "C"
{
#endif




#ifdef	__cplusplus
}
#endif

#endif				/* _CALENDARIO_H */
