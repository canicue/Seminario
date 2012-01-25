/* 
 * File:   rmps.h
 * Author: canicue
 *
 * Created on 31 de octubre de 2011, 00:45
 */

#ifndef _RMPS_H
#define	_RMPS_H
#include "tipos.h"

void agregar_rmp(RMP *rmp);
void borrar_rmp(char *rmp_id);
void modificar_rmp(char *rmp_id);
RMP *buscar_rmp(char *campo,char *valor);
#ifdef	__cplusplus
extern "C" {
#endif




#ifdef	__cplusplus
}
#endif

#endif	/* _RMPS_H */

